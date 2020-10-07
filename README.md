Here are two simple programs which are doing the same things: making a grid
follow the mouse cursor.

Once with Qt which can be made and executed with:

    $ qmake
    $ make
    $ ./qtperf
    
Once with XLib which can be made and executed with:

    $ cc -o xlibperf xlibperf.c -lX11
    $ ./xlibperf
    
If you maximize the window, you should see that with the Qt program, the
grid lag strongly behind the mouse even when it is moving relatively
slowly.  That issue does not happen with the XLib version.  I wonder what
the Qt version is doing more than the XLib one that justify that sharp
difference.  And if I can disable that stuff, with what drawbacks.
