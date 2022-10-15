import java.util.*;

public class ArrayListMagnet {

  public static void printAL (ArrayList<String> al) {

    for (String element : al) {
      System.out.print(element + "  ");
    }
    System.out.println("  ");
  }

  public static void main(String[] args) {

    ArrayList<String> a = new ArrayList<String>();

    // first line
    a.add(0, "zero");
    a.add(1, "one");
    a.add(2, "two");
    a.add(3, "three");
    printAL(a);

    //second line
    a.remove(2);
    if (a.contains("three")) {
      a.add("four");
    }
    printAL(a);

    //third line
    if (a.indexOf("four") != 4) {
      a.add(4, "4.2");
    }
    printAL(a);

    //fouth line
    if (a.contains("two")) {
      a.add("2.2");
    }
    printAL(a);
  }
}
