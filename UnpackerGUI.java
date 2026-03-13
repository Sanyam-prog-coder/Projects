import javax.swing.*;
import java.awt.*;
import java.io.*;

class UnpackerGUI extends JFrame 
{
    private byte Key = 0x11; // Decryption key

    public UnpackerGUI() 
    {
        setTitle("File Unpacker");
        setSize(500, 200);
        setLayout(new GridLayout(3, 1, 10, 10));
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JTextField txtFile = new JTextField();
        JButton btnBrowse = new JButton("Select Packed File");
        JButton btnStart = new JButton("Unpack Files");

        btnBrowse.addActionListener(e -> 
        {
            JFileChooser chooser = new JFileChooser();
            if (chooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION) 
            {
                txtFile.setText(chooser.getSelectedFile().getAbsolutePath());
            }
        });

        btnStart.addActionListener(e -> 
            {
            try 
            {
                unpackLogic(txtFile.getText());
                JOptionPane.showMessageDialog(this, "Success : Files Extracted...");
            } 
            catch (Exception ex) 
            {
                JOptionPane.showMessageDialog(this, "Error : " + ex.getMessage());
            }
        });

        add(new JLabel(" Select File to Unpack:"));
        add(btnBrowse);
        add(btnStart);

        setLocationRelativeTo(null);
    }

    private void unpackLogic(String packPath) throws Exception 
    {
        FileInputStream fiobj = new FileInputStream(new File(packPath));
        byte[] bHeader = new byte[100];
        int iRet;

        while ((iRet = fiobj.read(bHeader, 0, 100)) != -1) 
        {
            String header = new String(bHeader).trim();
            String[] tokens = header.split(" ");
            
            String fileName = tokens[0];
            int fileSize = Integer.parseInt(tokens[1]);

            byte[] buffer = new byte[fileSize];
            fiobj.read(buffer, 0, fileSize);

            FileOutputStream foobj = new FileOutputStream(new File(fileName));
            
            for (int i = 0; i < fileSize; i++) 
            {
                buffer[i] = (byte) (buffer[i] ^ Key); // XOR Decryption
            }
            foobj.write(buffer, 0, fileSize);
            foobj.close();
        }
        fiobj.close();
    }

    public static void main(String[] args) 
    {
        SwingUtilities.invokeLater(() -> new UnpackerGUI().setVisible(true));
    }
}