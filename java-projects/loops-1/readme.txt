/*******************************************************************************
 *  Name:  Michael Zhou  
 *  NetID:   myzhou
 *  Precept: P05
 ******************************************************************************/

Programming Assignment 1: Conditionals and Loops

Operating system (such as OS X or Windows):  OS X
Text editor (such as DrJava): DrJava               
Hours to complete assignment (optional): 2 hours    


/**********************************************************************
 *  How does the mean squared distance of a random walk grow
 *  as a function of the number of steps n?  Briefly justify your
 *  answer based on computational experiments.  (Describe the 
 *  experiments and list several data points.)
 *********************************************************************/

    The mean squared distance of a random walk seems to grow linearly 
    as a function of the number of steps n. As the number of steps n in 
    a given random walk increases from 10 to 100, for example, the value
    of the mean squared distance also increased in a similar fashion 
    from 10.72 to 100.72 (trials = 100). Similar results were observed
    when the number of trials was 1000 (10.28 to 100.846) and even when
    the number of steps was increased from 20 to 2000 with the same 
    number of trials (19.986 to 1991.214). Such trends were all the more
    evident when the number of trials was sufficiently large (100,000),
    with computational experiments bringing about these results:
    
    (n, Mean Squared Distance); Trials = 100000
    (20, 20.02614)        (85, 85.10672)
    (17, 16.9472)         (162, 161.87838)
    (238, 237.47498)      (972, 972.77954)
    (121, 121.321)        (335, 333.77728)
    (1214, 1213.75298)    (1685, 1684.66064)
    

/**********************************************************************
 *  Did you receive help from classmates, past COS 126 students, or
 *  anyone else?  Please list their names.  ("A Sunday lab TA" or 
 *  "Office hours on Thursday" is OK if you don't know their name.)
 **********************************************************************/

    On this assignment I received no outside help from any individuals.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

    As far as the assignments were concerned, there were no serious
    problems encountered during compiling or programming.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/

