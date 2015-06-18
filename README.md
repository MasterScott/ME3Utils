# ME3Utils
A collection of small utilities for Mass Effect 3, mostly useful for modders.

# ME3Log
Prints a log file for the game, relaying the original debug/assert messages.
Does this by a DLL hijack/forward of the binkw32 library, patching in a hook to the commonly used print functions.
Forwarding code based on source by WarrantyVoider.
