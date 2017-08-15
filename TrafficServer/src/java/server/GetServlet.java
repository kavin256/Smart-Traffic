/*
 * @author kavinranawella
 */

package server;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.*;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(urlPatterns = {"/update"})
        
public class GetServlet extends HttpServlet {

    String stm = "default stm";

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/event-stream");

        try (PrintWriter out = response.getWriter()) {
            
            while (!Thread.interrupted()){
                String tmp = new GetData().retrieve();
                if(!stm.equals(tmp)){

                    stm = tmp;
                    
                    out.println("data: "+stm);
                    out.println();
                    out.flush();
                }
            }
        } catch (Exception e) {
            System.out.println(e.toString());
        }  
    }
}