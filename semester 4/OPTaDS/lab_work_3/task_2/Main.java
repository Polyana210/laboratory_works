package org.example;

public class Main {

    public void main(String[] args) {
        String dataString = "a1.334t5Yz.78x3";
        String new_string = this.Task(dataString);
        System.out.println(new_string);
    }

    public String Task(String dataString){
    if (dataString.length()==1){return dataString;}
    else{
        StringBuilder new_str = new StringBuilder();
        boolean flag=true;
        for (int i=0; i<dataString.length()-1; i++){
            if (!isDigit(dataString.charAt(i))){flag=true;
                new_str.append(dataString.charAt(i));}
            else{
                if (!isDigit(dataString.charAt(i+1)) && flag){ flag=true; new_str.append(dataString.charAt(i));}
                else flag=false;
            }
        }
        if (isDigit(dataString.charAt(dataString.length()-1)) && !isDigit(dataString.charAt(dataString.length()-2))){
            new_str.append(dataString.charAt(dataString.length()-1));
        }else if (!isDigit(dataString.charAt(dataString.length()-1)))  new_str.append(dataString.charAt(dataString.length()-1));
        return new_str.toString();
    }}
    private static boolean isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
}