// Salvador Cortes Soancatl
// EE520 Spring 2021

Project Overview:
    For my final project I decided to do create a maze like environment using static elements.The obejectivbe was to put a robot at the start and have it explore until it finds the end of the maze. Use range sensors, wall following behaviors, and perhaps some kind of memory of where the robot has been, the second part of the project was to extend or improve the maze environment example. For example, use more complicated mazes. Generate random mazes. Build a map of the environment and navigate within it. 

    Overall the final product has a maze like environment based of static elements, however in my project I did not get to finalize random mazes as I was having many troubles with the image file and in workign with radomizing the .json file that would create this feature. There are some buys in my code but overall the purpose of the program is there, just Working wit Multiple Enviro imageseed some fine tunning. 


Challenges: 
    I face myny challenges in this project, below I have listed a few and explained how I came about working around them.
    1). Creating the maze:
        This was one of the most time consuming parts of this project, as I had o manually draw out the static lines that indicated the maze environment. This was tricky as I came to find out that the cordinate system was switched for the y-axis but the x-axis remained the same. One thing that helped me a lot in creating my first maze was creating one on paper and them drafting the cordinates for were the lines where to be on my maze. An aspect of the project that I did not get to solve was creating random mazes, I searched online on ideas of how to work with json files and in randomizing builds but had no luck as json is more of a data network transfer protocol and not very tangible to play with.  

    2). Working wit Multiple Enviro images
        Another chanllenge face was the fact that when trying some features presented in the example enviro libraries it sometimes did not work for a specific enviro image version. I started off usign the alpha enviro version but as I was trying out new features like Label and button I ran into compiling errors, such as the one below. When I switched to a different version my new code woould work for that feature yet older code did not work, there was some discrepency in the was the methods and enviro versions worked. 


    3). Creating the robot pictorial design
        Another aspect that was difficult was workign with the graphical desing of the robots and block as well as setting up sensors for this. This was very tricky as I felt as it was trial and error to see how the different parameters in the graphical assignation file worked. I think that it would help a lot if ther is more documentation regarding the set up of the graphical interface/ enviro environment. 

        This created a nice arrow pointing robot: 
        { "x": -7, "y": 15 },
        { "x": 0, "y": 10 },
        { "x": 7, "y": 15 }, 
        { "x": 0, "y": -7 }

Runnign the Code: 
    To run my code, please follow the below steps, 
    1. Clone my final project repository on your desktop
    2. Initiate Docker to run image: klavins/enviro:alpha 
    3. Go to my_project directory 
    3b. In an interner browser tab, go to http://localhost
    4. Run command: ESM Start
    5. Run command: Make
    6. RUn command: Enviro
    7. Done. 

Acknowledgements: 
    A. EE520 Provided Course Content (Enviro) location at https://github.com/klavinslab/enviro
    B. EE520 Tamara Bunuci Provided (Enviro) Starter Code
    C. EE520 Classmate Kai Helped me with writting location identifier method 



