/*******************************************************************************
 *  Name:    Michael Zhou
 *  NetID:   myzhou
 *  Precept: P05
 ******************************************************************************/

Programming Assignment 3: Recursive Graphics

OS: Mac OS X
Text editor: DrJava
Hours to complete assignment (optional): 20 hours



/**********************************************************************
 *  Describe your artistic creation, and how you went about writing   
 *  a program to produce it. If you found information about a
 *  fractal from somewhere (like our book, the booksite, or
 *  another offline or online source) mention it here. 
 *  (Note that you must not have used *code* from sources other than the
 *  book/booksite, and even such code should be cited in the program.)
 **********************************************************************/

 My pattern is a hybrid fractal that combines a hexagonal pattern of filled
 shapes through recursion together with nested circles. Specifically, the 
 hexagonal fractal formed rings of smaller hexagons within the bounds of 
 the next largest hexagon from the previous order, leaving behind an empty
 hexagonal space in the middle. This center was then filled with a nested
 circles pattern based on a pattern of nine-nested circles, five of which
 were four times as small as the larger circles of the nested circle pattern.
 This was done after the recursive calls for the drawing of each new order 
 of hexagon rings was complete by calling to a separate function at the end
 of the main hexagonal fractal recursion function that was responsible for 
 drawing nested circle patterns. These nested circles would be recursively 
 called and drawn within the centers of each hexagonal fractal iteration 
 inside the nested circle function and within each nested circle from the 
 previous order of nested circles. Information was found about the basic 
 forms of each of these patterns within the booksite and past programs
 listed on the archives of the COS 126 website from past years. However,
 no code was ever borrowed from other sources besides the book and booksite.

/**********************************************************************
 *  Did you receive help from classmates, past COS 126 students, or
 *  anyone else?  Please list their names.  ("A Sunday lab TA" or 
 *  "Office hours on Thursday" is ok if you don't know their name.)
 **********************************************************************/

I received help from a past COS 126 student, Bill Zhang.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
At one point the program seemed to be defective in terms of producing a good
recursive pattern in Art.java due to a failure to match up the two fractals
in their orders for each iteration that was called recursively. This turned
out to be just a small problem because of the reason mentioned above. Other
than that, there were no serioud problems encountered.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

