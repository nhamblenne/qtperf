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

Some information: I'm on Ubuntu 20.04 using the bundled Qt 5.12.8 and
lscpi gives the following information about my graphic card:

    01:00.0 VGA compatible controller: NVIDIA Corporation GM206 [GeForce GTX 950] (rev a1) (prog-if 00 [VGA controller])
        Subsystem: ZOTAC International (MCO) Ltd. GM206 [GeForce GTX 950]
        Flags: bus master, fast devsel, latency 0, IRQ 130
        Memory at de000000 (32-bit, non-prefetchable) [size=16M]
        Memory at c0000000 (64-bit, prefetchable) [size=256M]
        Memory at d0000000 (64-bit, prefetchable) [size=32M]
        I/O ports at e000 [size=128]
        Expansion ROM at 000c0000 [disabled] [size=128K]
        Capabilities: <access denied>
        Kernel driver in use: nouveau
        Kernel modules: nvidiafb, nouveau

Switching drivers from the default XOrg one to the nVidia one solved the lag
issue. I still wonder what explain the difference between Qt and XLib with
the XOrg driver.
