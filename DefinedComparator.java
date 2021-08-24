import java.util.Comparator;

// 
// Decompiled by Procyon v0.5.36
// 

class DefinedComparator implements Comparator<String>
{
    public int getYear(final String s) {
        int n = 0;
        for (int i = 7; i <= 10; ++i) {
            n = n * 10 + (Character.getNumericValue(s.charAt(i)) - 10);
        }
        return n;
    }
    
    public int getDate(final String s) {
        int n = 0;
        for (int i = 0; i <= 1; ++i) {
            n = n * 10 + (Character.getNumericValue(s.charAt(i)) - 10);
        }
        return n;
    }
    
    public int getMonth(final String s) {
        final String substring = s.substring(3, 6);
        final String[] array = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
        for (int i = 0; i < array.length; ++i) {
            if (substring.equals(array[i])) {
                return i;
            }
        }
        return -1;
    }
    
    @Override
    public int compare(final String s, final String s2) {
        final int date = this.getDate(s);
        final int date2 = this.getDate(s2);
        final int month = this.getMonth(s);
        final int month2 = this.getMonth(s2);
        final int year = this.getYear(s);
        final int year2 = this.getYear(s2);
        if (year < year2) {
            return -1;
        }
        if (year > year2) {
            return 1;
        }
        if (month < month2) {
            return -1;
        }
        if (month > month2) {
            return -1;
        }
        if (date < date2) {
            return -1;
        }
        if (date > date2) {
            return 1;
        }
        return 0;
    }
}
