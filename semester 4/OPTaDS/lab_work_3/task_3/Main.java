package org.example;

public class Main implements Job {
    public static Job job = new Main();
    public static void main(String[] args) {
        Manager.createWindow(job);
    }
    public void perform(StringBuilder dataString){
        if (dataString.length()==1){}
        else{
            StringBuilder new_str = new StringBuilder();
            boolean flag=true;
            int m = dataString.length();
            for (int i=0; i<m-1; i++){
                if (!isDigit(dataString.charAt(i))){flag=true;
                    dataString.append(dataString.charAt(i));}
                else{
                    if (!isDigit(dataString.charAt(i+1)) && flag){ flag=true; dataString.append(dataString.charAt(i));}
                    else flag=false;
                }
            }
            if (isDigit(dataString.charAt(dataString.length()-1)) && !isDigit(dataString.charAt(dataString.length()-2))){
                dataString.append(dataString.charAt(dataString.length()-1));
            }else if (!isDigit(dataString.charAt(dataString.length()-1)))  dataString.append(dataString.charAt(dataString.length()-1));
            dataString.delete(0,m);
        }}


    private static boolean isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }
}