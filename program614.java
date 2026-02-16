// Final Code of Unpacking

import java.io.*;
import java.nio.Buffer;
import java.nio.file.Files;
import java.util.*;

class program614
{
    public static void main(String A[]) throws Exception
    {
        // Variable Creation

        int i = 0;
        int iRet = 0;
        byte Key = 0x11;
        int FileSize = 0;

        Scanner sobj = null;
        String FileName = null;
        File fpackobj = null;
        File fobj = null;
        FileInputStream fiobj = null;
        FileOutputStream foobj = null;
        String Header = null;

        String Tokens[] = null;
        byte bHeader[] = new byte[100];
        byte Buffer[] = null;


        sobj =  new Scanner(System.in);

        System.out.println("Enter The Name OF Packed File : ");

        FileName = sobj.nextLine();

        fpackobj = new File(FileName);

        if(! fpackobj.exists())     // false
        {
            System.out.println("Error : There Is no such Packed File");
            return;
        }

        fiobj = new FileInputStream(fpackobj);

        // Read The Header
        while((iRet = fiobj.read(bHeader, 0, 100)) != -1)
        {
            Header = new String(bHeader);

            Header = Header.trim();

            Tokens = Header.split(" ");

            System.out.println("File Name : "+Tokens[0]);
            System.out.println("File Name : "+Tokens[1]);
        
            fobj = new File(Tokens[0]);

            fobj.createNewFile();

            foobj = new FileOutputStream(fobj);

            FileSize = Integer.parseInt(Tokens[1]);

            // Buffer For Reading the Data
            Buffer = new byte[FileSize];

            // Read from Packed File
            fiobj.read(Buffer,0,FileSize);

            // Decrypt the Data
            for(i = 0; i < FileSize; i++)
            {
                Buffer[i] = (byte)(Buffer[i] ^ Key);
            }

            // Write into Extracted file
            foobj.write(Buffer,0,FileSize);
        }
    }
}