package org.example;
import java.util.Scanner;
/*Дан список строк. Для каждой строки сформировать очередь из символов этой строки, которые являются скобками.
 Рассмотреть скобки вида: (), [], {}, <>. С помощью стека проверьте баланс скобок в этой строке.
 При проверке баланса учитывать правильную последовательность открытия и закрытия скобок.
 Примеры неправильного баланса скобок: "][", "({)}".*/
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Введите количество строк: ");
        int N = (int) scanner.nextDouble();
        String[] strings = new String[N];
        for (int i=0; i<N; i++){
            System.out.println("Введите "+(i+1)+" строку");
            strings[i] = scanner.next();
        }
        for (int i=0; i<N; i++) {
            String string = strings[i];

            if (Check_balance(string)) System.out.println("Скобки расставлены верно");
            else System.out.println("Скобки расставлены с ошибкой");
        }
    }

    public static boolean Check_balance(String string){
        System.out.println("Строка: "+ string);
        Queue queue = new Queue(100);
        String brackets = new String("()<>{}[]");
        for (int k = 0; k < string.length(); k++) {
            String l = String.valueOf(string.charAt(k));
            if (brackets.contains(l)) {
                queue.enqueue(l);
            }
        }
        Stack stack = new Stack();
        String open = "<{[(";
        while (!queue.isEmpty()){
            String ch = queue.dequeue();
            if (open.contains(ch)){
                stack.push(ch);
            }else{
                String op = stack.peek();
                switch (ch){
                    case "}": {
                        if (!op.equals("{")) return false;
                        break; }
                    case ">": {
                        if (!op.equals("<")) return false;
                        break; }
                    case "]": {
                        if (!op.equals("[")) return false;
                        break; }
                    case ")": {
                        if (!op.equals("(")) return false;
                        break; }
                } stack.pop();

            }

        }
        return true;
    }

    }
