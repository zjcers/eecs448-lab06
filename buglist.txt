=== Bugs ===

* isEmpty does not return false when an item is added to the list despite the list being verified as non-empty by toVector
* addBack seems to be implemented as addFront. Stopping inside of the add tens items using addBack test with gdb reveals the given sequence is reversed, which gives evidence for this. objdump confirms that this hypothesis is not true, though the behavior still suggests that the implementation of addBack is similar to a simple addFront implementation.
* removeFront doesn't decrement size, or do anything at all. The vector returned by toVector() is unchanged after the list (supposedly) is emptied by removeFront. This seems to be caused by a failure to detect an empty list. This is probably caused by isEmpty's bug
* removeBack is as broken as removeFront, likely for similar reasons