import java.io.*;
import java.util.*;
import java.net.ServerSocket;
import java.net.Socket;

class Server{
    static Scanner in = new Scanner(System.in);
    public static void main(String args[]) throws IOException{
        System.out.print("Enter the port :");
        int port = in.nextInt();

        ServerSocket server = new ServerSocket(port);

        System.out.println("Server Started!");
        while (true) {
            Socket client = server.accept();
            try{
                System.out.println("New Client Connected and it's request is ");
                InputStreamReader isr = new InputStreamReader(client.getInputStream());
                BufferedReader reader = new BufferedReader(isr);
                String line = reader.readLine();
                while (!line.isEmpty()) {
                    System.out.print("\t");
                    System.out.println(line);
                    line = reader.readLine();
                }
            }
            catch(Exception e){
                client.close();
                System.out.println("Client is no more connected");
                continue;
            }

            PrintWriter out = new PrintWriter(client.getOutputStream());
            String s = "HTTP/1.1 200 OK\n";
            s += "Host Name: " + server.getLocalSocketAddress() + " \nPort: " + port;
            s += " \nConnection: close \nContent-Type: text/html \n" + "charset: UTF-8 \n";
            s += "\r\n<h1>Welcome to the HTTP SERVER</h1>";
            out.println(s);
            out.flush();
            out.close();

            client.close();
            System.out.println("Client is Closed");
        }

    }
}
