import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Regex {
    public static void main(String args[]) {
        // String to be scanned to find the pattern.
        String line = "1101";
        String pattern = "1[0]+1";

        // Create a Pattern object
        Pattern r = Pattern.compile(pattern);

        // Now create matcher object.
        Matcher m = r.matcher(line);
        if (m.find()) {
            System.out.println("Found value: " + m.group(0));
        } else {
            System.out.println("NO MATCH");
        }
    }
}