/*
 * @author kavinranawella
 */

package server;

import java.sql.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.util.logging.Level;
import java.util.logging.Logger;

public class GetData {
    
    String resultStream = "Default";
    static ResultSet rs;
    static Connection con; 
    static int indexCheck = 999;

    public String retrieve() {

        try {
          Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost/arduinodb","root","");
            Statement stmt = con.createStatement();
            rs = stmt.executeQuery("select * from junction1");

            while(rs.next()){
                resultStream = rs.getInt(2)+" "+rs.getInt(3)+" "+rs.getInt(4)+" "+rs.getInt(5);
                indexCheck = rs.getInt(1);

            }

            con.close();
            Thread.sleep(5000);
            
        } catch (SQLException ex) {
            Logger.getLogger(GetData.class.getName()).log(Level.SEVERE, null, ex);
        } 
       catch (ClassNotFoundException ex) {
            Logger.getLogger(GetData.class.getName()).log(Level.SEVERE, null, ex);
        } catch (InterruptedException ex) {
            Logger.getLogger(GetData.class.getName()).log(Level.SEVERE, null, ex);
        }
        return resultStream;
    }
}
