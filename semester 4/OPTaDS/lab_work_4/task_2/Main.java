package org.example;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.io.File;

import java.util.*;
import java.util.Scanner;

/*Информация о пользовании дисками в пункте проката: фамилия и инициалы клиента; название диска;
 дата выдачи диска; дата предполагаемого возврата диска; дата фактического возврата.
 Вывести список клиентов, просрочивших возврат дисков
 (в случае просрочки возврата нескольких дисков фамилию клиента выводить только один раз).*/
public class Main {
    public static void main(String[] args) throws IOException {
        List<Map<String, String>> list_values = new ArrayList<>();
        try {
            Reader reader = new FileReader("file.csv");
            BufferedReader buffReader = new BufferedReader(reader);
            String line;
            while((line = buffReader.readLine()) != null) {
                Map<String, String> map = new TreeMap<>();
                String[] parts = line.split(";");

                map.put("DateEnd", Arrays.asList(parts).get(4));
                map.put("DateSupposed", Arrays.asList(parts).get(3));
                map.put("DateStart", Arrays.asList(parts).get(2));
                map.put("DiskName", Arrays.asList(parts).get(1));
                map.put("Name", Arrays.asList(parts).get(0));
                list_values.add(map);
            }
            buffReader.close();
        } catch(FileNotFoundException e) {

            File newFile = new File("file.csv");
            boolean created = newFile.createNewFile();
            System.out.println("Файл не найден. Cоздадим его. Добавьте данные");
            add_elem(list_values);

        } catch(IOException e) {
            System.out.println("Ошибка ввода-вывода");
        }
        Scanner scanner = new Scanner(System.in);
        boolean fl=true;
        while(fl) {

            System.out.println("Выберите действие:");
            System.out.println("1) Добавить строку");
            System.out.println("2) Удалить строку");
            System.out.println("3) Изменить данные");
            System.out.println("4) Вывести список должников");
            System.out.println("5) Вывести общий список");
            System.out.println("10) Выход");
            int N = (int) scanner.nextDouble();
            switch (N){
                case 1:
                    add_elem(list_values);
                    break;
                case 2:
                    delete_elem(list_values);
                    break;
                case 3:
                    replace_elem(list_values);
                    break;
                case 4:
                    print_list_debt(list_values);
                    break;
                case 5:
                    print_list(list_values);
                    break;
                case 10:
                    fl=false;
                    break;
                default:
                    System.out.println("Попробуйте еще раз");
            }
        };
    }

    public static List<Map<String, String>> delete_elem(List<Map<String, String>> list_values) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите номер строки, которую хотите удалить: ");
        int N = (int) scanner.nextDouble()-1;
        list_values.remove(N);
        return list_values;
    }

    public static List<Map<String, String>> add_elem(List<Map<String, String>> list_values) {
        Scanner scanner = new Scanner(System.in);
        Map<String, String> map = new TreeMap<>();
        String info;
        System.out.println("Введите Фамилию и инициалы: ");
        info = scanner.next();
        map.put("Name", info);
        System.out.println("Введите название диска: ");
        info = scanner.next();
        map.put("DiskName", info);
        System.out.println("Дату выдачи диска в формате DD-MM-YYYY: ");
        info = scanner.next();
        map.put("DateStart",info);
        System.out.println("Дату предполагаемую дату возврата в формате DD-MM-YYYY: ");
        info = scanner.next();
        map.put("DateSupposed", info);
        System.out.println("Дату возврата диска в формате DD-MM-YYYY: ");
        info = scanner.next();
        map.put("DateEnd", info);
        list_values.add(map);
        return list_values;
    }
    public static List<Map<String, String>> replace_elem(List<Map<String, String>> list_values) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите номер строки, которую хотите отредактировать: ");
        int N = (int) scanner.nextDouble()-1;
        System.out.println("Введите поле, которое хотите отредактировать: ");
        String key = scanner.next();
        System.out.println("Введите новое значение: ");
        String val = scanner.next();
        list_values.get(N).replace(key, val);
        return list_values;
    }

    public static void print_list(List<Map<String, String>> list_values) {
        System.out.println("Дата возврата     Дата начала        Ожидаемая дата      Название диска          ФИО     ");
        for (int i = 0; i < list_values.size(); i++) {
            for (Map.Entry<String, String> pair : list_values.get(i).entrySet()) {
                String value = pair.getValue();
                System.out.print(value + "          ");
            }
            System.out.println();
        }
    }

    public static void print_list_debt(List<Map<String, String>> list_values) {
        Set<String> list_debt = new HashSet<>();
        for (int i = 0; i < list_values.size(); i++) {
            String[] date1 = list_values.get(i).get("DateEnd").split("-");
            Date date_end = new Date( Integer.parseInt(date1[2])-1900,  Integer.parseInt(date1[1])-1,  Integer.parseInt(date1[0]));
            String[] date2 = list_values.get(i).get("DateSupposed").split("-");
            Date date_sup = new Date( Integer.parseInt(date2[2])-1900,  Integer.parseInt(date2[1])-1,  Integer.parseInt(date2[0]));
            if (date_end.getTime() > date_sup.getTime()){
                list_debt.add(list_values.get(i).get("Name"));
            }
        }

        if (list_debt.size()==0) System.out.println("Список должников пуст");
        else {
            System.out.println("Список должников:");
            for (String text : list_debt) {
                System.out.println(text);
            }
        }
    }
}