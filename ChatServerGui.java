import java.io.*;
import java.net.*;
import java.awt.event.*;
import java.awt.Color;
import javax.swing.*;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function     : Server
// Description  : To Chat with Client By networking
// Auther       : Sanyam BhupendraKumar Ravne
// Date         : 11/11/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

class Server extends JFrame implements ActionListener
{
    JFrame fobj;
    JTextField tobj;
    JLabel msgobj, syobj;
    JButton btnobj;

    ServerSocket ssobj;
    Socket sobj;
    PrintStream pobj;
    BufferedReader bobj1;

    Server(String title, int width, int height)
    {
        fobj = new JFrame(title);

        msgobj = new JLabel("Message");
        msgobj.setBounds(50,50,100,30);

        tobj = new JTextField();
        tobj.setBounds(150,50,150,30);

        btnobj = new JButton("Send");
        btnobj.setBounds(120,100,100,30);

        syobj = new JLabel("Server Says :");
        syobj.setBounds(50,210,250,30);

        fobj.getContentPane().setBackground(Color.ORANGE);

        fobj.add(msgobj);
        fobj.add(tobj);
        fobj.add(btnobj);
        fobj.add(syobj);

        btnobj.addActionListener(this);

        fobj.setLayout(null);
        fobj.setSize(width,height);
        fobj.setVisible(true);
        fobj.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Start server socket in background
        Thread serverThread = new Thread(() -> startServer());
        serverThread.start();
    }

    void startServer()
    {
        try
        {
            ssobj = new ServerSocket(5100);
            System.out.println("Server is waiting at port 5100...");

            sobj = ssobj.accept();
            System.out.println("Client connected!");

            pobj = new PrintStream(sobj.getOutputStream());
            bobj1 = new BufferedReader(new InputStreamReader(sobj.getInputStream()));

            String str1;

            while((str1 = bobj1.readLine()) != null)
            {
                syobj.setText("Client says: " + str1);
                System.out.println("Client says: " + str1);
            }
        }
        catch(Exception e)
        {
            System.out.println("Error in server thread: " + e);
        }
    }

    public void actionPerformed(ActionEvent aobj)
    {
        try
        {
            String str2 = tobj.getText();
            pobj.println(str2);
            syobj.setText("Server says: " + str2);
            tobj.setText("");
        }
        catch(Exception e)
        {
            System.out.println("Send button error: " + e);
        }
    }
}

class ChatServerGui
{
    public static void main(String A[])
    {
        new Server("Server", 400, 300);
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Input : Hi       Output : Server Says : hi
//
////////////////////////////////////////////////////////////////////////////////////////////////////////