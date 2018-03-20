# sound-maker
C++ program made to generate .wav music files

This program was made to help introduce C++ programmers to the generation of simple .wav sound files

STEPS:
1. Make sure you have "make" (haha)
2. Check that you can compile with minimum C++11 standard
3. Initialize sound maker object:
```
  // #include "sound_maker.hpp" at the top!
  
  SoundMaker S("file_name.wav"); // Step #3
```
4. Add as many samples you want to your sound file
```
  SoundMaker S("file_name.wav"); // Step #3
  
  // sample values is an integer in range -32767 through 32767
  S.add_sample( (int) (channel_1), (int) (channel_2) ); // Step #4
  // ... <- more samples here
  S.add_sample( (int) (channel_1), (int) (channel_2) ); // Step #4
```
5. Once you have finished adding samples make sure to call done()!!!
```
  SoundMaker S("file_name.wav"); // Step #3
  
  // sample values has two arguements of an integer in the range -32767 through 32767
  S.add_sample( (int) channel_1, (int) channel_2 ); // Step #4
  // ... <- more samples here
  S.add_sample( (int) channel_1, (int) channel_2 ); // Step #4

  S.done(); // Step #5
```
6. Run "make" and enjoy your music file!!!
