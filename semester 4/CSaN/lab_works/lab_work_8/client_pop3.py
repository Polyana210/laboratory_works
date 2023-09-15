import sys

import poplib
import email
from email.header import decode_header


def do_decode_header(header):
    """Декодировать заголовок по ключу 'header'."""
    header_parts = decode_header(header)
    res = []
    for decoded_string, encoding in header_parts:
        if encoding:
            decoded_string = decoded_string.decode(encoding)
        elif isinstance(decoded_string, bytes):
            decoded_string = decoded_string.decode("ascii")
        res.append(decoded_string)

    return "".join(res)


def get_part_info(part):
    """Получить текст сообщения в правильной кодировке."""
    encoding = part.get_content_charset()
    # Если кодировку определить не удалось, используется по умолчанию
    if not encoding:
        encoding = sys.stdout.encoding
    message = part.get_payload(decode=True).decode(encoding, errors="ignore").strip()

    return message, encoding


def get_message_info(message):
    """Получить текст сообщения в правильной кодировке."""
    message_text, encoding, mime = "Нет тела сообщения", "-", "-"

    if message.is_multipart():
        for part in message.walk():
            if part.get_content_type() in ("text/html", "text/plain"):
                message_text, encoding = get_part_info(part)
                break  # Только первое вхождение
    else:
        message_text, encoding= get_part_info(message)

    return message_text, encoding


if __name__ == "__main__":

    # Данные почтового сервера
    server = "pop.yandex.ru"
    port = 995
    login = input('Адрес почты: ')
    password = input('Пароль: ')

    try:
            # Создание защищенного соединения и авторизация
            mailserver = poplib.POP3_SSL(server, port)
            mailserver.user(login)
            mailserver.pass_(password)

            stat = mailserver.stat()
            print("\nВсего писем: {}, объем: {:.2f} Мб.".
                  format(stat[0], stat[1] / 2**20))

            # Полный список писем
            response, messages, octets = mailserver.list()
            print("\nСписок писем: ", response.decode())

            
            # Чтение первых сообщений
            fl = True
            while fl:
              print("\nВведите номер письма, которое будем читать (0 - выход): ")
              num = int(input())
              if num>0 and num <=len(messages):
                  message_num = num
                  response, raw_message, octets = mailserver.retr(message_num)
                  if not response.decode().startswith("+OK"):
                      print("Не удалось получить письмо №", message_num)

                  # Преобразование сообщения в объект email.Message
                  raw_message = b"\n".join(raw_message)
                  message = email.message_from_bytes(raw_message)
                  # Получение текста письма
                  text, encoding = get_message_info(message)

                  #print(raw_message)
                  # Вывод информации о письме
                  print("\n№{} ---"
                        "\n  - от: '{}'"
                        "\n  - тема: '{}'"
                        "\n  - дата: '{}'"
                        "\n  - объем: {:.2f} Кб."
                        "\n  -  Кодировка: {}"
                        "\n  - содержимое (первые 100 симв.):\n\"{}\"".
                        format(message_num,
                              do_decode_header(message["From"]),
                              do_decode_header(message["Subject"]),
                              message["Date"],
                              octets / 2**10,
                              encoding,
                              text[:100]))
              elif num==0:
                fl=False
              else:
                  print("Некорректный номер письма.")
    except poplib.error_proto as err:
            print("Возникла следующая ошибка:", err)
    finally:
            mailserver.quit()
