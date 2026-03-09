import java.io.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;

// Done 

//////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : StudyLog
/// Description : Constructor class 
/// Author      : Ravne Sanyam Bhupendrakumar
/// Date        : 06-March-2026
/// 
//////////////////////////////////////////////////////////////////////////////////

class StudyLog
{
    private LocalDate Date;
    private String Subject;
    private double Duration;
    private String Description;

    public StudyLog(LocalDate a, String b, double c, String d)
    {
        this.Date = a;
        this.Subject = b;
        this.Duration = c;
        this.Description = d;
    }

    public LocalDate getDate()
    {
        return this.Date;
    }

    public String getSubject()
    {
        return this.Subject;
    }

    public double getDuration()
    {
        return this.Duration;
    }

    public String getDescription()
    {
        return this.Description;
    }

    @Override
    public String toString()
    {
        return Date+" | "+Subject+" | "+Duration+" | "+Description;
    }
}

//////////////////////////////////////////////////////////////////////////////////
/// 
/// Function    : StudyTracker
/// Author      : Ravne Sanyam Bhupendrakumar
/// Date        : 06-March-2026
/// 
//////////////////////////////////////////////////////////////////////////////////

class StudyTracker
{
    public ArrayList <StudyLog>Database = new ArrayList<StudyLog>();

    public void InsetLog()
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("-------------------------------------------------------------");
        System.out.println("-------------- Enter Valid Details Of Your Study ------------");
        System.out.println("-------------------------------------------------------------");

        LocalDate Dateobj = LocalDate.now();

        System.out.println("Please Enter the Name of Subject like C/C++/Java/Python");
        String sub = sobj.nextLine();

        System.out.println("Enter The time period of Study in hours");
        double dur = sobj.nextDouble();
        sobj.nextLine();

        System.out.println("Please Provide the Description of your Study");
        String desc = sobj.nextLine();

        StudyLog studyobj = new StudyLog(Dateobj, sub, dur, desc);

        Database.add(studyobj);

        System.out.println("Study log gets stored succesfully");
        System.out.println("-------------------------------------------------------------");

    }

    //////////////////////////////////////////////////////////////////////////////////

    public void DisplayLog()
    {
        System.out.println("-------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("------------------ Nothing to display -----------------------");
            System.out.println("-------------------------------------------------------------");
            return;
        }

        System.out.println("----------- Log report of marvellous study tracker ----------");
        System.out.println("-------------------------------------------------------------");

        for(StudyLog s : Database)
        {
            System.out.println(s);
        }

        System.out.println("-------------------------------------------------------------");
    }

    //////////////////////////////////////////////////////////////////////////////////

    public void ExportCSV()
    {
        if(Database.isEmpty())
        {
            System.out.println("-------------------------------------------------------------");
            System.out.println("------------------- Nothing to export -----------------------");
            System.out.println("-------------------------------------------------------------");
            return;
        }

        String FileName = "MarvellousStudyTracker.CSV";

        try(FileWriter fwobj = new FileWriter(FileName))
        {
            fwobj.write("Date,Subject,Duration,Description\n");

            for(StudyLog s : Database)
            {
                fwobj.write(s.getDate()+","+
                            s.getSubject().replace(",", " ")+","+
                            s.getDuration()+","+
                            s.getDescription().replace(",", " ")+"\n");
            }

            System.out.println("Data Gets Exported in CSV : "+FileName);
        }
        catch(Exception eobj)
        {
            System.out.println("Exception Occured in CSV Handling");
        }
    }

    //////////////////////////////////////////////////////////////////////////////////

    public void SummaryByDate()
    {
        System.out.println("-------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("Nothing to Display as database is empty");
            System.out.println("-------------------------------------------------------------");
            return;
        }

        System.out.println("-------------- Summary by Date from Study Tracker -----------");
        System.out.println("-------------------------------------------------------------");

        TreeMap <LocalDate, Double>tobj = new TreeMap<LocalDate, Double>();

        LocalDate lobj = null;
        double d = 0.0, old = 0.0;

        for(StudyLog sobj : Database)
        {
            lobj = sobj.getDate();
            d = sobj.getDuration();

            if(tobj.containsKey(lobj))
            {
                old = tobj.get(lobj);
                tobj.put(lobj, d + old);
            }
            else
            {
                tobj.put(lobj,d);
            }
        } // End of for

        // Display details as per Date

        for(LocalDate l : tobj.keySet())
        {
            System.out.println("Date : "+l+" Total Study Duration "+ tobj.get(l));
        }

        System.out.println("-------------------------------------------------------------");
    }

    //////////////////////////////////////////////////////////////////////////////////

    public void SummaryBySubject()
    {
        System.out.println("-------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("Nothing to Display as database is empty");
            System.out.println("-------------------------------------------------------------");
            return;
        }

        System.out.println("------------- Summary by subject from Study Tracker ---------");
        System.out.println("-------------------------------------------------------------");

        TreeMap <String, Double>tobj = new TreeMap<String, Double>();

        String s = null;
        double d = 0.0, old = 0.0;

        for(StudyLog sobj : Database)
        {
            s = sobj.getSubject();
            d = sobj.getDuration();

            if(tobj.containsKey(s))
            {
                old = tobj.get(s);
                tobj.put(s, d + old);
            }
            else
            {
                tobj.put(s,d);
            }
        } // End of for

        // Display details as per subject

        for(String str : tobj.keySet())
        {
            System.out.println("Subject : "+str+" Total Study Duration "+ tobj.get(str));
        }

        System.out.println("-------------------------------------------------------------");        
    }
}

class MarvellousStudyTracker
{
    public static void main(String A[])
    {   
        Scanner sobj = new Scanner(System.in);
        StudyTracker stobj = new StudyTracker();

        System.out.println("-------------------------------------------------------------");
        System.out.println("----------- Welcome To Marvellous Study Tracker -------------");
        System.out.println("-------------------------------------------------------------");

        int iChoice = 0;
        
        do
        {
            System.out.println("Please Select appropriate option");
            System.out.println("1 : Inset new Study log");
            System.out.println("2 : View All Study log");
            System.out.println("3 : Export Study log to CSV file");
            System.out.println("4 : Summary of Study log by date");
            System.out.println("5 : Summary of Study log by Subject");
            System.out.println("6 : Exit the Application");

            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                // Inset new Study log
                case 1 : 
                    stobj.InsetLog();
                    break;

                // View All Study log
                case 2 :
                    stobj.DisplayLog();
                    break;

                // Export Study log to CSV file    
                case 3 :
                    stobj.ExportCSV();
                    break;

                // Summary of Study log by date
                case 4 :
                    stobj.SummaryByDate();
                    break;

                // Summary of Study log by subject
                case 5 :
                    stobj.SummaryBySubject();
                    break;

                // Exit the Application
                case 6 :
                    System.out.println("-------------------------------------------------------------");
                    System.out.println("-------- Thank you for using Marvellous Study Tracker -------");
                    System.out.println("-------------------------------------------------------------");
                    break;

                default :
                    System.out.println("Please Enter Valid options ");
                    break;
            }

        }while(iChoice != 6); // End of do While

    }   // End of Main
}   // End of Starter Class