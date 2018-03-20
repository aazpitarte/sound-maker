// author: etratipza@gmail.com
// date: 03-17-2018
// inspired by: 
//		http://www.topherlee.com/software/pcm-tut-wavformat.html
//		http://www.cplusplus.com/forum/beginner/166954/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "sound_maker.hpp"
#include <map>


constexpr double two_pi = 6.283185307179586476925286766559;
constexpr double max_amplitude = 32760;
constexpr double hz = 44100.0;


// Function that will convert frequency and time duration into .wav file samples
void generate_data( SoundMaker& S, double freq, double amount_time = 1.0 ) {
	
	double frequency = freq;
	double seconds = amount_time;

	double chan_1 = 0.0; // channel 1
	double chan_2 = 0.0; // channel 2
	
	double amplitude = (double) 32760.0;
	int period;
	frequency == 0.0 ? period = -1 : period = (int) (hz / (2.0 * frequency)) ; // number of samples in a wave length

	double step = max_amplitude / period;

	int samples = hz * seconds;
	int x;
	double value;

	for ( int n = 0; n < samples; n++ ) {
		
		chan_2 += step;
		x = n % (2 * period);
		value = sin( ((two_pi * n * frequency)  / hz ));

		// Channel 1 has sine wave
		chan_1 = amplitude * value;

		// Channel 2 will have a half circle wave
		chan_2 = sqrt(  pow(2*32760.0, 2) * (1.0 - ( pow(x - (period) ,2) / pow(period,2))) ) - 32760.0;

		if (frequency == 0.0)
			chan_2 = 0.0;

		S.add_sample( (int) (chan_1), (int) (chan_2) ); // Add sample to .wav file

	}
}


int main() {

	srand( time(NULL));

	// music_map[ note_letter ][ octave 0 - 8 ] == frequency
	std::map< char, double* > music_map;

	// https://pages.mtu.edu/~suits/notefreqs.html
	// Upper-case letters denote sharp notes
	double c_notes[] = {16.35, 32.70, 65.41, 130.81, 261.63, 523.25, 1046.50, 2093.00, 4186.01};
	music_map['c'] =  c_notes;
	double C_notes[] = {17.32, 34.65, 69.30, 138.59, 277.18, 554.37, 1108.73, 2217.46, 2217.46};
	music_map['C'] = C_notes;
	double d_notes[] = {18.35, 36.71, 73.42, 146.83, 293.66, 587.33, 1174.66, 2349.32, 4698.63};
	music_map['d'] = d_notes;
	double D_notes[] = {19.45, 38.89, 77.78, 155.56, 311.13, 622.25, 1244.51, 2489.02,  4978.03};
	music_map['D'] = D_notes;
	double e_notes[] = {20.60, 41.20, 82.41, 164.81, 329.63, 659.25, 1318.51, 2637.02, 5274.04};
	music_map['e'] = e_notes;
	double f_notes[] = {21.83, 43.65, 87.31, 174.61, 349.23, 698.46, 1396.91, 2793.83, 5587.65};
	music_map['f'] = f_notes;
	double F_notes[] = {23.12, 46.25, 92.50, 185.00, 369.99, 739.99, 1479.98, 2959.96, 5919.91};
	music_map['F'] = F_notes;
	double g_notes[] = {24.50, 49.00, 98.00, 196.00, 392.00, 783.99, 1567.98, 3135.96, 6271.93};
	music_map['g'] = g_notes;
	double G_notes[] = {25.96, 51.91, 103.83, 207.65, 415.30, 830.61, 1661.22, 3322.44, 6644.88};
	music_map['G'] = G_notes;
	double a_notes[] = {27.50, 55.00, 110.00, 220.00, 440.00, 880.00, 1760.00, 3520.00, 7040.00};
	music_map['a'] = a_notes;
	double A_notes[] = {29.14, 58.27, 116.54, 233.08, 466.16, 932.33, 1864.66, 3729.31, 7458.62};
	music_map['A'] = A_notes;
	double b_notes[] = {30.87, 61.74, 123.47, 246.94, 493.88, 987.77, 1975.53, 3951.07, 7902.13};
	music_map['b'] = b_notes;
	
	// 12 notes in scale
	char notes[] = {'c', 'C', 'd', 'D', 'e', 'f', 'F', 'g', 'G', 'a', 'A', 'b'};

	// Create file and initialize .wav file headers
	SoundMaker S("new_sound.wav");
	

	// Loop through all notes in 9 octaves @440hz
	//
	// for (auto elem : music_map) {
	// 	std::cout << elem.first << std::endl;
	// 	for ( int i = 0; i < 9; i++ ) {
	// 		generate_data(S, elem.second[i], 0.5);
	// 	}
	// }


	// Generate c scale starting at the 3rd octave
	generate_data(S, 0.0, 0.1);
	generate_data(S, music_map[ 'c'][3], 1.0); generate_data(S, 0.0, 0.1);
	generate_data(S, music_map[ 'd'][3], 1.0); generate_data(S, 0.0, 0.1);
	generate_data(S, music_map[ 'e'][3], 1.0); generate_data(S, 0.0, 0.1);
	generate_data(S, music_map[ 'f'][3], 1.0); generate_data(S, 0.0, 0.1);
	generate_data(S, music_map[ 'g'][3], 1.0); generate_data(S, 0.0, 0.1);
	generate_data(S, music_map[ 'a'][3], 1.0); generate_data(S, 0.0, 0.1);
	generate_data(S, music_map[ 'b'][3], 1.0); generate_data(S, 0.0, 0.1);
	generate_data(S, music_map[ 'c'][4], 1.0); generate_data(S, 0.0, 0.1);
	generate_data(S, 0.0, 0.1);

	// Generate random notes
	//
	// for ( int n = 0; n < 30; n++) {
	// 	generate_data(S, music_map[  notes[ rand() % 12] ][ rand() % 6 + 2] , 0.25 * (rand() % 2 + 1)  );
	// }
	
	S.done(); // Final header adjustments and close file
	std::cout << "FINISHED" << std::endl;

	return 0;
}

