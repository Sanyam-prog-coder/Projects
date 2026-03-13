import java.io.*;
import java.net.*;
import java.awt.event.*;
import java.awt.Color;
import javax.swing.*;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : Client
// Description  : To Chat with Server By networking
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 11/11/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

class Client extends JFrame implements ActionListener
{
    JFrame fobj;
    JTextField tobj;
    JLabel msgobj, syobj;
    JButton btnobj;

    Socket sobj;
    PrintStream pobj;
    BufferedReader bobj1;

    Client(String title, int width, int height)
    {
        fobj = new JFrame(title);

        msgobj = new JLabel("Message");
        msgobj.setBounds(50, 50, 100, 30);

        tobj = new JTextField();
        tobj.setBounds(150, 50, 150, 30);

        btnobj = new JButton("Send");
        btnobj.setBounds(120, 100, 100, 30);

        syobj = new JLabel("Client Says : ");
        syobj.setBounds(50, 210, 250, 30);

        fobj.getContentPane().setBackground(Color.LIGHT_GRAY);

        fobj.add(msgobj);
        fobj.add(tobj);
        fobj.add(btnobj);
        fobj.add(syobj);

        btnobj.addActionListener(this);

        fobj.setLayout(null);
        fobj.setSize(width, height);
        fobj.setVisible(true);
        fobj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // connect to server in background
        Thread clientThread = new Thread(() -> startClient());
        clientThread.start();
    }

    void startClient()
    {
        try
        {
            sobj = new Socket("localhost", 5100);
            System.out.println("Client connected to Server successfully");

            pobj = new PrintStream(sobj.getOutputStream());
            bobj1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));

            String str1;
            while ((str1 = bobj1.readLine()) != null)
            {
                syobj.setText("Server says: " + str1);
                System.out.println("Server says: " + str1);
            }
        }
        catch (Exception e)
        {
            System.out.println("Error in client thread: " + e);
        }
    }

    public void actionPerformed(ActionEvent aobj)
    {
        try
        {
            String str2 = tobj.getText();
            pobj.println(str2);
            syobj.setText("Client says: " + str2);
            tobj.setText("");
        }
        catch (Exception e)
        {
            System.out.println("Send button error: " + e);
        }
    }
}

class ChatClientGui
{
    public static void main(String A[])
    {
        new Client("Client", 400, 300);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Input : Hello        Output : Client says : Hello
//
////////////////////////////////////////////////////////////////////////////////////////////////////////