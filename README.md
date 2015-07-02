# ME3Utils
A collection of small utilities for Mass Effect 3, mostly useful for modders.

# ME3Log
Prints a log file for the game, relaying the original debug/assert messages.
Does this by a DLL hijack/forward of the binkw32 library, patching in a hook to the commonly used print functions.
Forwarding code based on source by WarrantyVoider.

# Install
Build with release as target, and copy the dll to the directory where your masseffect3 executable resides.

If you are currently not using any dlc verification patch bundled as binkw32.dll, rename your binkw32.dll to binkw23.dll and then rename the dll you built to binkw32.dll.

If you already use a patched binkw32.dll, backup that, then overwrite it with the newly built dll.