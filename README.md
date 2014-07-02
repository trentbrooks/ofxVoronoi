![Voronoi Diagram](http://farm8.staticflickr.com/7193/6967101789_519a469cd0_b.jpg)

Simple addon to make voronoi diagrams in openFrameworks. 

The algorithm is a modified version of Stephan Fortune's sweep line algorithm
http://ect.bell-labs.com/who/sjf/

Orignal Code from Shane O'Sullivan
http://www.skynet.ie/~sos/mapviewer/voronoi.php

UPDATE
This is a modified version of Todd's original ofxVoronoi addon. I've replaced the precompiled Voro++ 2D library (libvoro++_2d32.a), with the original source as created by Chris Rycroft (https://codeforge.lbl.gov/scm/?group_id=108). Works on OSX and Windows. There was also a memory leak with setBounds I had to remove.

Trent Brooks

