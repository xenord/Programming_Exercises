package com.DirtyDevs;

import java.util.Scanner;

/**
 * Created by francescobenetello on 21/02/16.
 */
public class DataDifference {

    int day, month, year;


    public int monthToDay (int month) {
        switch (month) {
            case 1: month = 31;
                break;
            case 2: month = 28;
                break;
            case 3: month = 31;
                break;
            case 4: month = 30;
                break;
            case 5: month = 31;
                break;
            case 6: month = 30;
                break;
            case 7: month = 31;
                break;
            case 8: month = 31;
                break;
            case 9: month = 31;
                break;
            case 10: month = 31;
                break;
            case 11: month = 30;
                break;
            case 12: month = 31;
                break;
            default:
                System.out.println("Il numero inserito non è un mese, riprovare!");
        }
        return month;
    }

    public static void main (String[] args) {
        // Definisco metodo per lo standard input
        Scanner console = new Scanner(System.in);

        //Inserimento prima data

        System.out.println("Data 1");
        System.out.print("Inserisci il giorno: ");
        int giorno1 = console.nextInt();
        System.out.print("Inserisci il mese: ");
        int mese1 = console.nextInt();
        System.out.print("Inserisci l'anno: ");
        int anno1 = console.nextInt();

        //Inserimento seconda data

        System.out.println("Data 2");
        System.out.print("Inserisci il giorno: ");
        int giorno2 = console.nextInt();
        System.out.print("Inserisci il mese: ");
        int mese2 = console.nextInt();
        System.out.print("Inserisci l'anno: ");
        int anno2 = console.nextInt();

    }
}
