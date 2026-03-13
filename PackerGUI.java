import javax.swing.*;
import java.awt.*;
import java.io.*;

class PackerGUI extends JFrame
{
    private byte key = 0x11;

    public PackerGUI()
    {
        setTitle("File Packer");
        setSize(500, 250);
        setLayout(new GridLayout(6, 1, 10, 10));
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        JTextField txtFolder = new JTextField();
        JButton btnBrowse = new JButton("Browse Button");
        JTextField txtPackName = new JTextField("Packed.lib");
        JButton btnStart = new JButton("Pack File");
        
        btnBrowse.addActionListener(e ->
            {
                JFileChooser chooser = new JFileChooser();
                chooser.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);

                if(chooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION)
                {
                    txtFolder.setText(chooser.getSelectedFile().getAbsolutePath());
                }
            });
        
        btnStart.addActionListener(e ->
            {
                try
                {
                    packLogic(txtFolder.getText(),txtPackName.getText());
                    JOptionPane.showMessageDialog(this, "Sucess : Files Packed...");
                }
                catch(Exception ex)
                {
                    JOptionPane.showMessageDialog(this, "Error : "+ex.getMessage());
                }
            });

        add(new JLabel("Select Source Folder:"));
        add(txtFolder);
        add(btnBrowse);

        add(new JLabel("Destination File Name:"));
        add(txtPackName);
        add(btnStart);

        setLocationRelativeTo(null);
    }

    private void packLogic(String folderPath, String packName) throws Exception 
    {
        File fobj = new File(folderPath);

        if (!fobj.exists() || !fobj.isDirectory()) throw new Exception("Invalid Directory");

        FileOutputStream foobj = new FileOutputStream(new File(packName));
        File[] fArr = fobj.listFiles();

        for (File file : fArr) 
            {
                if (file.getName().endsWith(".AAE")) 
                {
                    // Create 100-byte header
                    String headerStr = String.format("%-100s", file.getName() + " " + file.length());
                    foobj.write(headerStr.getBytes(), 0, 100);

                    FileInputStream fiobj = new FileInputStream(file);
                    byte[] buffer = new byte[1024];
                    int iRet;

                    while ((iRet = fiobj.read(buffer)) != -1) 
                    {
                        for (int j = 0; j < iRet; j++) 
                        {
                            buffer[j] = (byte) (buffer[j] ^ key); // XOR Encryption
                        }
                        foobj.write(buffer, 0, iRet);
                    }
                    fiobj.close();
                }
        }
        foobj.close();
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new PackerGUI().setVisible(true));
    }
}