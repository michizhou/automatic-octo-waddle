/******************************************************************************
  *  Name: Alex Chien   
  *  NetID: ac30   
  *  Precept: P05 
  *
  *  Partner Name: Michael Zhou   
  *  Partner NetID: myzhou
  *  Partner Precept: P05 
  * 
  *  Description: Datatype that represents a travelling salesperson's tour with
  *               a linked list implementation.
  *****************************************************************************/
public class Tour {
    
    // Instance variable
    private Node first; // first and representative node of the tour
    
    // helper linked-list data type
    private class Node {
        private Point p; // point stored in the node
        private Node next; // pointer to next node in linked-list
    }
    
    // creates an empty tour
    public Tour()
    {
        first = null;
    }
    
    // creates the 4-point tour a->b->c->d->a (for debugging)
    public Tour(Point a, Point b, Point c, Point d) {
        first = new Node();
        Node x = new Node();
        Node y = new Node();
        Node z = new Node();
        first.p = a;
        x.p = b;
        y.p = c;
        z.p = d;
        first.next = x;
        x.next = y;
        y.next = z;
        z.next = first;
    }
    
    // returns the number of points in this tour
    public int size()
    {
        int count = 0;
        
        // case for empty tour
        if (first == null) {
            return count;
        }
        
        // else traverse tour and increment count
        Node arrow = first;
        do {
            count++;
            arrow = arrow.next;
        } while (arrow != first);
        
        return count;
    }
    
    // returns the length of this tour
    public double length()
    {
        double length = 0.0;
        
        // case for empty tour
        if (first == null) {
            return length;
        }
        
        // else traverse tour and sum length
        Node arrow = first;
        do {
            length = length + arrow.p.distanceTo(arrow.next.p);
            arrow = arrow.next;
        } while (arrow != first);
        return length;
    }
    
    // draws this tour to standard drawing
    public void draw() 
    {
        // traverse tour and draw it
        if (first != null) {
            Node arrow = first;
            do {
                arrow.p.drawTo(arrow.next.p);
                arrow = arrow.next;
            } while (arrow != first);
        }
    }
    
    // prints this tour to standard output
    public void show()
    {
        // traverse tour and print points in sequence
        if (first != null) {
            Node arrow = first;
            do {
                StdOut.println(arrow.p);
                arrow = arrow.next;
            } while (arrow != first);
        }
    }
    
    // inserts p using the nearest neighbor heuristic
    public void insertNearest(Point p)
    {
        
        // case for empty tour
        if (first == null) {
            first = new Node();
            first.p = p;
            first.next = first; // make it circular
        }
        
        // otherwise insert the point.
        else {
            Node store = new Node();
            double dist = 0.0;
            double min = Double.POSITIVE_INFINITY;
            Node arrow = first;
            
            // go through the tour, check dist. from each node to p.
            do {
                dist = arrow.p.distanceTo(p); // dist from current node to p
                if (dist < min) { // if current node is the nearest so far,
                    min = dist; // then update min distance
                    store = arrow; // and store the node.
                }
                arrow = arrow.next;
            } while (arrow != first);
            
            // create and insert node containing new point
            Node newPoint = new Node();
            newPoint.p = p;
            newPoint.next = store.next;
            store.next = newPoint;
        }
    }  
    
    // inserts p using the smallest increase heuristic
    public void insertSmallest(Point p)
    {
        Node newPoint = new Node(); // create new node with point
        newPoint.p = p;
        
        // case for empty tour, p is the first point
        if (first == null) {
            first = newPoint;
            first.next = first; // make it circular
        }
        
        else // otherwise insert the point.
        {
            Node store = new Node();
            double deltaDist = 0.0;
            double originalDist = 0.0;
            double min = Double.POSITIVE_INFINITY;
            Node arrow = first;
            
            // go thru tour, insert newPoint after every tour point, and check
            do {
                originalDist = arrow.p.distanceTo(arrow.next.p);
                // calculate change in the length after inserting newPoint
                deltaDist = newPoint.p.distanceTo(arrow.p) + 
                    newPoint.p.distanceTo(arrow.next.p) - originalDist;
                if (deltaDist < min) {
                    min = deltaDist; // update min change in tour length
                    store = arrow; // and store the node
                }
                arrow = arrow.next;
            } while (arrow != first);
            
            // insert node containing the new point
            newPoint.next = store.next;
            store.next = newPoint;
        }
    }
    
    // test client
    public static void main(String[] args)
    {
        // define 4 points that are the corners of a square
        Point a = new Point(100.0, 100.0);
        Point b = new Point(500.0, 100.0);
        Point c = new Point(500.0, 500.0);
        Point d = new Point(100.0, 500.0);
        
        // create the tour a -> b -> c -> d -> a
        Tour squareTour = new Tour(a, b, c, d);
        
        // print the tour to standard output
        squareTour.show();
        
        // test size(), length(), and draw()
        System.out.println("size: " + squareTour.size());
        System.out.println("length: " + squareTour.length());
        StdDraw.setXscale(0, 600);
        StdDraw.setYscale(0, 600);
        squareTour.draw();
        
        // test insertNearest()
        Point e = new Point(300.0, 300.0);
        squareTour.insertNearest(e);
        StdDraw.setPenRadius(0.01);
        StdDraw.setPenColor(StdDraw.BLUE);
        squareTour.draw();
        
        // test insertSmallest()
        Point f = new Point(400.0, 400.0);
        squareTour.insertSmallest(f);
        StdDraw.setPenRadius(0.02);
        StdDraw.setPenColor(StdDraw.RED);
        squareTour.draw();
    }
}