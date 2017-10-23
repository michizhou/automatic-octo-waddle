/*******************************************************************************
 *  Name:  Michael Zhou  
 *  NetID:   myzhou
 *  Precept: P05
 ******************************************************************************/

Programming Assignment 4: Hamming Codes

OS: OS X
Text editor: DrJava
Hours to complete assignment (optional): 10 hours



/**********************************************************************
 *  Which simulator did you use to develop your TOY programs?
 *  TOY.java or Visual X-TOY 7.1 (the toy.jar)?
 **********************************************************************/

Visual X-TOY 7.1

/**********************************************************************
 *  Describe what, if anything, you use each of the registers for
 *  in encode.toy.
 **********************************************************************/
R[1]: first message bit from standard input
R[2]: second message bit from standard input
R[3]: third message bit from standard input
R[4]: fourth message bit from standard input
R[5]: value of 0001
R[6]: addition of R[5] and R[1] standard input
R[7]: half of first parity bit using xor of R[1] and R[2]
R[8]: half of second parity bit using xor of R[1] and R[3]
R[9]: half of first parity bit using xor of R[2] and R[3]
R[A]: first parity bit using xor of R[7] and R[4]
R[B]: second parity bit using xor of R[8] and R[4]
R[C]: third parity bit using xor of R[9] and R[4]
R[D]: 
R[E]:
R[F]:


/**********************************************************************
 *  Describe what, if anything, you use each of the registers for
 *  in decode.toy.
 **********************************************************************/
R[1]: first message bit from standard input
R[2]: second message bit from standard input
R[3]: third message bit from standard input
R[4]: fourth message bit from standard input
R[5]: value of 0001
R[6]: addition of R[5] and R[1] standard input
R[7]: first parity bit from standard input; then result of R[A] & R[B]
R[8]: second parity bit from standard input; then result of R[A] & R[C]
R[9]: third parity bit from standard input; then result of R[B] & R[C]
R[A]: parity check of first, second, and fourth message bits
R[B]: parity check of first, third, and fourth message bits
R[C]: parity check of second, third, and fourth message bits
R[D]: parity check of all message bits
R[E]:
R[F]:



/**********************************************************************
 *  Did you receive help from classmates, past COS 126 students, or
 *  anyone else?  Please list their names.  ("A Sunday lab TA" or 
 *  "Office hours on Thursday" is OK if you don't know their name.)
 **********************************************************************/

I did receive some help from past COS 126 student Matt Wang.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/



/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
As part of my class privileges, I would like to use one late day to excuse
the turn-in time for this assignment and its components beyond the usual 
midnight deadline on October 24. If that could be applied to this computing
assignment and its components I would really appreciate it.