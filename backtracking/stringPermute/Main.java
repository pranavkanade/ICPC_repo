import java.util.Vector;

/**
 * Created by farzicoder on 8/10/16.
 */
public class Main {
    private final static String str = "abc";

    private static void permute(String str1, Vector<String> arr){
        int length = arr.size();

        if(length == 0)
            System.out.println(str1);
        else {
            Vector<String> arr1;
            for (int i = 0; i < length; i++) {
                // new instance of vector containing the chars remaining for permutation
                arr1 = new Vector<>();

                arr1.addAll(arr);
                // create new String which holds the current instance of required permutation
                String str2 = str1.concat(arr.elementAt(i));

                arr1.removeElementAt(i);
                // recursion on the remaining string
                permute(str2, arr1);
            }

        }
    }

    public static void main(String [] args){
        int length = str.length();

        for(int i = 0; i < length; i++){
            String str1 = new String(Character.toString(str.charAt(i)));

            Vector<String> arr = new Vector<>();

            for(int j = 0; j < length; j++){
                if(i != j){
                    arr.add(Character.toString(str.charAt(j)));
                }
            }

            permute(str1, arr);
        }
    }
}
