import static org.junit.Assert.*;
import org.junit.Test;

public class webifyTest {

    @Test
    @SuppressWarnings("static-access")
    public void middlemanTest(){
        webify webify = new webify();
        
        assertEquals("<h1>", webify.txtToHTML("#", 1));
        assertEquals("</em>", webify.txtToHTML("/", 0));
        assertEquals("-", webify.txtToHTML("-", 0));
    }
}
