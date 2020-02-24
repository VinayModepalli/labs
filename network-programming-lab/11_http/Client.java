import java.io.*;
import java.util.*;

import java.net.Socket;


class Client{
    static Scanner in = new Scanner(System.in);
    public static void main(String args[]) throws IOException{
		System.out.print("Enter the hostname : ");
		String hostname = in.nextLine();
        System.out.print("Enter the port :");
        int port = in.nextInt();

        Socket client = new Socket(hostname,port);

			
		PrintWriter out = new PrintWriter(client.getOutputStream());
		String s = "GET / HTTP/1.1\n";
		s += "Host Name: " + hostname + " \nPort: " + port;
		s += "\r";
		out.println(s);
		out.flush();
		try{
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
			System.out.println("Server is no more connected");
		}

		client.close();
		System.out.println("Server connection is Closed");

    }
}
