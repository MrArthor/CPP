ANS4)
(1)
package coreservlets; 
import java.io.*; 
import javax.servlet.*; 
import javax.servlet.http.*; 
import java.net.*;
public class SearchEngines extends HttpServlet 
{   
public void doGet(HttpServletRequest request,HttpServletResponse response)  
 throws ServletException, IOException 
{  
String searchString = request.getParameter("searchString");    
if ((searchString == null)  
 (searchString.length() == 0)) 
{ 
reportProblem(response,"Missing search string");       
return;     
}     
searchString = URLEncoder.encode(searchString);     
String searchEngineName =  request.getParameter("searchEngine");    
 if ((searchEngineName == null) 
(searchEngineName.length() == 0)) 
{ 
reportProblem(response,"Missing search engine name");       
return;    
}    
String searchURL = SearchUtilities.makeURL(searchEngineName, searchString);     
if (searchURL != null) 
{
response.sendRedirect(searchURL);  
} 
else 
{
reportProblem(response, "Unrecognized search engine");     
}   
} 
private void reportProblem(HttpServletResponse response,               String message)       
throws IOException 
{ 
 response.sendError(response.SC_NOT_FOUND, message); 
 } 
}

(2)
package coreservlets; 
public class SearchSpec
 {
private String name, baseURL;   
public SearchSpec(String name,String baseURL) 
{
this.name = name;     
this.baseURL = baseURL;   
}  
public String makeURL(String searchString) 
{
return(baseURL + searchString);   
}   
public String getName() 
{ 
return(name);   
} 
}

(3)
package coreservlets; 
public class SearchUtilities 
{
private static SearchSpec[] commonSpecs = { new SearchSpec("Google", "http://www.google.com/search?q="),new SearchSpec("AllTheWeb","http://www.alltheweb.com/search?q="),       new SearchSpec("Yahoo","http://search.yahoo.com/bin/search?p="),       new SearchSpec("AltaVista","http://www.altavista.com/web/results?q="),new SearchSpec("Lycos","search.lycos.com/default.asp?query="),       new SearchSpec("HotBot","http://hotbot.com/default.asp?query="),       new SearchSpec("MSN","http://search.msn.com/results.asp?q="),     };   
public static SearchSpec[] getCommonSpecs() 
{
return(commonSpecs);   
}  
public static String makeURL(String searchEngineName,String searchString) 
{
SearchSpec[] searchSpecs = getCommonSpecs();     
String searchURL = null;    
 for(int i=0; i<searchSpecs.length; i++) 
{
SearchSpec spec = searchSpecs[i];
if (spec.getName().equalsIgnoreCase(searchEngineName)) 
{
searchURL = spec.makeURL(searchString);         
break;       
}    
}    
return(searchURL);   
} 
}
(4)
package coreservlets; 
import java.io.*; 
import javax.servlet.*; 
import javax.servlet.http.*; 
public class SearchEngineForm extends HttpServlet 
{   
public void doGet(HttpServletRequest request, HttpServletResponse response)       
throws ServletException, IOException 
{
response.setContentType("text/html");     
PrintWriter out = response.getWriter();     
String title = "One-Stop Web Search!";     
String actionURL = "/servlet/coreservlets.SearchEngines";     
String docType = "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0 " + "Transitional//EN\">\n";     
out.println (docType + "<HTML>\n" + "<HEAD><TITLE>" + title + "</TITLE></HEAD>\n" + "<BODY BGCOLOR=\"#FDF5E6\">\n" +        "<CENTER>\n" + "<H1>" + title + "</H1>\n" + "<FORM ACTION=\"" + actionURL + "\">\n" + "  Search keywords: \n" +"  <INPUT TYPE=\"TEXT\" NAME=\"searchString\"><P>\n");     
SearchSpec[] specs = SearchUtilities.getCommonSpecs();     
for(int i=0; i<specs.length; i++) 
{
String searchEngineName = specs[i].getName();       out.println("<INPUT TYPE=\"RADIO\" " + "NAME=\"searchEngine\" " +  "VALUE=\"" + searchEngineName + "\">\n");       out.println(searchEngineName + "<BR>\n");     

}     
out.println ("<BR>  <INPUT TYPE=\"SUBMIT\">\n" +        "</FORM>\n" + "</CENTER></BODY></HTML>");   
} 
}
