
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
 

public class GpsServlet extends HttpServlet{
   
      public void doGet(HttpServletRequest request, HttpServletResponse response) throws  ServletException, IOException {   
          
                 PrintWriter out = response.getWriter();  

         // GPS coordinates (+ for Noth or East, - for South or West)         
                out.write("+45.508831, -73.566197");
                                 
}
}