/*
given an array and value k find the value that is nearest to k and should not exceed k that can be formed by summing up array elements 
1
n      k
2000 1801
1973 1916 1962 1959 1909 2000 1957 1916 1909 1979 1973 1990 1938 1952 1922 1921 1979 1954 1922 1980 1934 1989 1925 1913 1913 1956 1903 1961 1924 1915 1904 1949 1930 1917 1959 1938 1917 1967 1906 1977 1946 1978 1966 1983 1982 1988 1903 1960 1941 1925 1939 1975 1913 1963 1939 1977 1919 1942 1989 1994 1956 1992 1994 1938 1961 1952 1975 1977 1919 1932 1953 1964 1962 1918 1998 1943 1957 1953 1902 1998 1977 1992 1924 1941 1907 1962 1969 1977 1903 1958 1922 1959 1901 1916 1996 1961 1919 1922 1937 1937 1906 1941 1952 1967 1911 1902 1961 1967 1954 1914 1916 1982 1905 1939 1922 1963 1901 1942 1939 1903 1999 1913 1913 2000 1928 1908 1912 1946 1982 1901 1935 1987 1941 1938 1905 1903 1939 1965 1922 1992 1978 1937 1973 1982 1976 1946 1997 1928 1988 1987 1930 1938 1999 1995 1989 1978 1954 1901 1924 1935 1901 1910 1973 1993 1999 1977 1948 1938 1941 1969 1981 1918 1957 1906 1952 1932 1951 1948 1911 1990 1986 1941 1980 1985 1987 1968 1962 1940 1920 1937 1975 1972 1946 1947 1965 1997 1976 1964 1934 1916 1984 1966 1934 1940 1971 1937 1924 1974 1984 1934 1915 1969 1926 1994 1905 1912 1962 1967 1904 1981 1903 1930 1953 1901 1928 1969 1997 1903 1984 1982 1919 1967 1947 1904 1958 1970 1940 1981 1943 1975 1967 1957 1995 1944 1903 2000 1908 1964 1918 1911 1996 1972 1940 2000 1972 1967 1920 1920 1970 1903 1953 1988 1969 1952 1943 1979 1921 1982 1959 1915 1956 1977 1923 1950 1921 1925 1901 1928 1940 1918 1990 1936 1990 1929 1987 1913 1995 1907 1933 1916 1909 1937 1955 1930 1988 1997 1908 1960 1930 1918 1926 1985 1947 1901 1987 1967 1925 1987 1946 1917 1957 1987 1904 1946 1915 1990 1958 1961 1996 1942 1977 1957 1979 1983 1986 1918 1980 1945 1930 1961 1914 1955 1946 1960 1955 1984 1978 1932 1922 1923 1948 1978 1961 1903 1923 1975 1992 1933 1988 1940 1974 1916 1948 1904 1998 1985 1922 1929 1929 1951 1990 1942 1957 1987 1902 1964 1970 1979 1995 1943 1954 1994 1921 1914 1948 1995 1941 1991 1979 1928 1930 1953 1995 1929 1956 1992 1913 1929 1973 1941 1931 1962 1935 1988 2000 1988 1903 1969 1918 1949 1963 1923 1942 1935 1989 1989 1930 1929 1931 1908 1908 1961 1912 1954 1941 1920 1945 1954 1948 1969 1946 1931 1930 1980 1970 1929 1919 1972 1949 1937 1920 1912 1911 1913 1998 1999 1953 1927 1979 1983 1987 1938 1995 1950 1991 1936 1969 1988 1989 1969 1956 1986 1951 1938 1966 1920 1918 1936 1991 1967 1972 1962 1930 1983 1974 1927 1933 1978 1906 1912 1960 1944 1949 1955 1945 1992 1942 1966 1979 1982 1934 1986 1967 1984 1923 1984 1955 1941 1920 1997 1959 1943 1958 1988 1977 1983 1966 1910 1960 1923 1921 1971 1918 1921 1977 1963 1964 1918 1928 1942 1999 1913 1928 1918 1948 1902 1901 1902 1942 1920 1950 2000 1963 1959 1939 1939 1941 1957 2000 1952 1931 1920 1974 1949 1993 1951 1963 1956 1968 1942 1950 1919 1954 1929 1936 1901 1930 1988 1954 1924 1908 1903 1975 1922 1913 1966 1912 1953 1974 1912 1956 1904 1983 1929 1904 1975 1979 1918 1983 1999 1959 1932 1969 1912 1912 1956 1964 1993 1943 1969 1916 1950 1923 1991 1923 1935 1908 1935 1939 1981 1946 1994 1936 1928 1975 1940 1955 1905 1957 1937 1903 1916 1920 1923 1979 1983 1978 1995 1975 1921 1963 1991 1922 1986 1933 1997 1972 1992 1931 1911 1972 1928 1956 1907 1955 1930 1998 1961 1935 1907 1997 1989 1974 1968 1912 1904 1950 1941 1998 1925 1961 1961 1967 1935 1998 1951 1931 1969 1942 1913 1979 1913 1940 1935 1971 1994 1916 1921 1955 1950 1979 1903 1991 1952 1923 1902 1955 1924 1942 1905 2000 1955 1965 1966 1941 1914 1968 1971 1934 1909 1935 1965 1973 1974 1951 1996 1919 1966 1916 1925 1916 1946 1928 1906 1997 1902 1959 1903 1925 1952 1907 1925 1906 1923 1942 1998 1936 1910 1920 1970 1970 1954 1934 1943 1927 1984 1990 1946 1901 1957 1970 1968 1902 1949 1973 1998 1950 1983 2000 1927 1935 1959 1951 1992 1981 1992 1990 1917 1953 1909 1938 1923 1915 1923 1917 1941 1958 1906 1938 1958 1962 1908 1926 1963 1908 1950 1912 1910 1933 1963 1936 1919 1921 1938 1962 1954 1929 1903 1922 1934 1964 1959 1956 1978 1933 1924 1918 1990 1929 1908 1947 1942 1967 1924 1956 1974 1974 1919 1983 1958 1981 1970 1976 1954 1907 1989 1907 1988 1992 1928 1921 1955 1938 1928 1984 1970 1951 1953 1911 1931 1960 1957 1972 1926 1981 1979 2000 1906 1997 1934 1963 1929 1956 1990 1934 1962 1978 1940 1949 1921 1919 1921 1927 1908 1948 1910 1929 1950 1963 1939 1980 1974 1996 1903 2000 1928 1981 1951 1933 1929 1936 1995 1958 1991 1936 1991 1905 1913 1983 1905 1934 1953 1926 1912 1961 1925 1922 1989 1975 1936 1980 1906 1909 1927 1909 1960 1954 1941 1910 1938 1970 1998 1984 1927 1988 1919 1969 1944 1983 1951 1949 1968 1956 1974 1980 1916 1998 1901 1956 1924 1988 1935 1930 1948 1913 1990 1908 1966 1930 1969 1955 1951 1966 1938 1929 1906 1908 1998 1949 1991 2000 1997 1958 1955 1922 1937 1970 1972 1989 1978 1995 1928 1964 1976 1976 1977 1917 1983 1994 1947 1951 1949 1949 1969 1938 1978 1974 1946 1975 1974 1936 1974 1971 1993 1929 1944 1982 1950 1915 1922 1979 1962 1950 1995 1989 1925 1971 1906 1907 1916 1904 1909 1916 1952 1977 1954 1929 1950 1999 1903 1924 1934 1929 1946 1978 1957 1941 1911 1958 1956 1933 1937 1969 1982 1931 1909 1958 1953 1914 1964 1920 1969 1924 1936 1921 1901 1989 1901 1902 1939 1904 1977 1924 1984 1974 1901 1992 1915 1964 1949 1922 1996 1937 1942 1929 1967 1950 1986 1971 1964 1901 1943 1984 1976 1978 1904 1976 1918 1957 1930 1956 1912 1906 1979 1995 1932 1931 1986 1946 1994 1934 1967 1941 1971 1908 1921 1989 1909 1958 1912 1924 1910 1954 1908 1986 1983 1963 1961 2000 1919 1942 1955 1930 2000 1985 1924 1931 1915 1909 1928 1961 1995 1994 1953 1917 1953 1974 1957 1961 1983 1968 1985 1993 1973 1944 1978 1955 1906 1990 1954 1925 1932 1960 1954 1983 1944 1930 1913 1911 1990 1940 1923 1984 1985 1975 2000 1989 2000 1909 1901 1983 1976 1937 1975 1949 1980 1904 1903 1986 1993 1909 1962 1976 1968 1967 1958 1964 1996 1970 1974 1986 1961 1948 1921 1945 1974 1973 1985 1974 1981 1986 1908 1956 1922 1934 1956 1902 1937 1911 1939 1981 1919 2000 1957 1938 1966 1966 1901 1914 1988 1926 1999 1948 1973 1919 1945 1947 1991 1929 1972 1971 1966 1979 1979 1988 1964 1986 1941 1952 1996 1979 1932 1966 1930 1940 1904 1947 1906 1956 1960 1993 1982 1910 1992 1954 1981 1936 1952 1971 1917 1923 1994 1982 1953 1924 1921 1916 1909 1961 1967 1957 1991 1951 1922 1920 1990 1977 1919 1995 1933 1978 1939 1966 1940 1931 1971 1920 1966 1923 1990 1934 1997 1935 1968 1950 1958 1988 1917 1919 1949 1984 1975 1939 1934 1996 1911 1975 1973 1929 1970 1957 1958 1908 1922 1997 1938 1992 1916 1956 1966 1958 1941 1963 1944 1908 1964 1902 1996 1980 1920 1996 1915 1994 1934 2000 1941 1996 1975 1965 1924 1996 1973 1982 1955 1994 1978 1945 1938 1946 1952 1955 1955 1992 1917 1998 2000 1932 1951 1947 1912 1970 1942 1978 1915 1975 1930 1908 1971 1956 1972 1946 1951 1945 1927 1957 1990 1957 1901 1979 1954 1952 1934 1908 1996 1902 1905 1995 1934 1956 1941 1997 1977 1934 1926 1944 1908 1955 1951 1930 1910 1974 1928 1912 1970 1906 1969 1912 1914 1921 1990 1967 1973 1975 1926 1968 1929 1983 1914 1962 1990 1906 1910 1966 1939 1935 1961 1998 1942 1963 1980 1903 1989 1907 1915 1958 1964 1935 1921 1978 1955 1963 1996 1979 1937 1922 1998 1965 1904 1911 1978 1993 1968 1939 1910 1906 1974 1923 1956 1967 1985 1935 1969 1973 1993 1935 1983 1956 1969 1903 1985 1924 1965 1981 1902 1954 1902 2000 1970 1957 1962 2000 1901 1930 1938 1910 1987 1911 1984 1942 1929 1969 1928 1998 1993 1972 1932 1975 1928 1901 1930 1912 1976 1946 1944 1929 1951 1945 1980 1921 1901 1942 1920 1901 1923 1957 1963 1909 1920 1946 1903 1948 1966 1930 1997 1959 1902 1929 1985 1981 1981 1966 1944 1908 1912 1988 1936 1914 1932 1968 1934 1985 1909 1905 1937 1983 1914 1999 1991 1985 1997 1993 1984 1962 1975 1981 1920 1976 1961 1957 1956 1993 1922 1951 2000 1933 1938 1987 1999 1922 1954 1932 1906 1914 1989 1942 1996 1954 1993 1939 1990 1941 1931 1973 1902 1905 1905 1974 1932 1965 1930 1939 1909 1951 1990 1960 1936 1927 1947 1934 1948 1952 1917 1905 1966 1957 1999 1913 1962 1943 1951 1951 1983 1934 1924 1984 1938 1928 1909 1922 1945 1938 1960 1953 1941 1949 1965 1976 1928 1911 1961 1927 1914 1929 1984 1931 1986 1982 1944 1947 1976 1946 1998 1958 1979 1973 1993 1917 1952 1902 1990 1996 1991 1949 1901 1931 1950 1965 1958 1977 1927 1918 1955 1940 1947 1938 1923 1984 1971 1966 1982 1946 1911 1979 1955 1942 1951 2000 1958 1903 1953 1947 1950 1943 1947 1902 1974 1996 1966 1983 1924 1944 1901 1979 1936 1999 1968 1958 1934 1939 1975 1915 1936 1937 1994 1943 1978 1996 1942 1987 1950 1994 1985 1952 1988 1932 1953 1961 1979 1971 1944 1903 1914 1996 1933 1901 1946 2000 1958 1979 1990 1984 1945 1978 1973 1990 1920 1950 1938 1913 1989 1987 1958 1973 1990 1945 1956 1943 1958 1987 1965 1953 1941 1930 2000 1973 1931 1997 1924 1940 1927 1914 1924 1971 1943 1996 1961 1914 1997 1998 1926 1985 1936 1935 1910 1926 1931 1917 1920 1940 1903 1984 1944 1943 1965 1943 1967 1995 1939 1991 1935 1965 1956 1910 1936 1998 1957 1948 1911 1905 1997 1988 1990 1984 1974 1951 1961 1904 1919 1980 1996 1922 1915 1939 1916 1980 1982 1983 1926 1972 1973 1960 1937 1928 1921 1924 1977 1977 1923 1987 1934 1919 1974 1975 1902 1947 1925 1963 1902 1943 1994 1997 1916 1961 1936 1984 1992 1969 1966 1917 1940 1990 1929 1976 1969 1949 1951 1945 1978 1925 1983 1911 1943 1908 1985 1997 1954 1961 1911 1907 1955 1956 1904 1971 1916 1991 1954 1959 1959 1971 1976 1998 1912 1904 1926 1980 1904 1928 1976 1933 1953 1958 1995 1947 1965 1979 1995 1970 1991 1905 1928 1946 1961 1931 1968 1928 1973 1973 1987 1983 1943 1914 1933 1954 1969 1958 1985 1972 1937 1960 1957 1941 1969 1951 1988 1933 1982 1982 1954 1972 1939 1981 1969 1951 1964 1936 1978 1936 1908 1916 1971 1902 1929 1903 1907 1949 1912 1991 1921 1948 1902 1929 1989 1970 1979 1928 1954 1960 1909 1907 1984 1947 1940 1952 1997 1903 1940 1927 1990 1999 1942 1960 1953 1923 1914 1959 1971 1925 1902 1943 1925 1903 1971 1913 1925 1902 1992 1978 1961 2000 1937 1996 1999 1976 1948 1947 1930 1939 1973 1971 1937 1967 1983 1989 1941 1996 2000 1963 1973 1901 1958 1997 1955 1928 1961 1979 1929 1952 1909 1942 1903 1997 1937 1901 1924 1936 2000 1953 1926 1924 1975 1915 1942 1957 1903 1982 1905 1954 1997 1977 1906 1954 1973 1961 1933 1933 1991 1914 1936 400 500
output 1800
*/
import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class UnboundedKnapsack {

    // Complete the unboundedKnapsack function below.
    static int unboundedKnapsack(int k, int[] arr) {
        int n = arr.length;
        boolean[][] dp = new boolean[n+1][k+1];
        int max=0;
        Arrays.fill(dp[0], false);
        for(int i=1; i<=n; i++){
            dp[i][0] = false;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=k; j++){
                System.out.println(i);
                if(j<arr[i-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else if(j%arr[i-1]==0){
                    if(j>max && j<=k)
                        max=j;
                    dp[i][j] = true;
                }
                else{
                    if(dp[i][j-arr[i-1]]==true){
                        dp[i][j]=true;
                        if(j>max && j<=k)
                            max=j;
                    }
                    else if(dp[i-1][j]==true)
                        dp[i][j] = true;
                    else{
                        dp[i][j] = false;
                    }
                }
            }
        }
    //    for(int i=0; i<=n; i++){
    //        for(int j=0; j<=k; j++){
    //            System.out.print(dp[i][j]+" ");
    //        }
    //        System.out.println();
    //    }
        return max;

    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        
        int t = scanner.nextInt();
        while(t>0){
            --t;
        
        
        int n = scanner.nextInt();

        int k = scanner.nextInt();

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            int arrItem = scanner.nextInt();
            arr[i] = arrItem;
        }

        int result = unboundedKnapsack(k, arr);
        System.out.println(result);
        }

        scanner.close();
    }
}
