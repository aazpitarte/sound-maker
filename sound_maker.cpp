// author: etratipza@gmail.com
// date: 03-17-2018
// inspired by: 
//		http://www.topherlee.com/software/pcm-tut-wavformat.html
//		http://www.cplusplus.com/forum/beginner/166954/

#include <iostream>
#include <fstream>
#include <string>
#include "sound_maker.hpp"

SoundMaker::SoundMaker( std::string file_name = "sound.wav" ) {
	this->file.open( file_name, std::ios::binary );
	this->header_size = this->set_header( this->file );
	this->size_pos = 4;
}

size_t SoundMaker::set_header( std::ofstream& f ) {
	f << "RIFF----WAVEfmt ";
	this->put_bits( f,     16, 4 );  // length of format data
	this->put_bits( f,      1, 2 );  // PCM - integer samples
	this->put_bits( f,      2, 2 );  // two channels (stereo file)
	this->put_bits( f,  44100, 4 );  // samples per second (Hz)
	this->put_bits( f, 176400, 4 );  // (Sample Rate * BitsPerSample * Channels) / 8
	this->put_bits( f,      4, 2 );  // bytes needed for 2 channels in one sample
	this->put_bits( f,     16, 2 );  // bits per sample
	f << "data----";	

	return f.tellp();
}


size_t SoundMaker::done() {
	this->file_size = this->file.tellp();
	this->data_size = this->file_size - this->header_size;

	// Write data size in header
	this->file.seekp( this->header_size - 4 );
	this->put_bits( this->file, this->data_size, 4);

	// Write file size in header
	this->file.seekp( this->size_pos );
	this->put_bits( this->file, this->file_size - 8, 4 );	

	this->file.close();
	return this->file_size;	
}


void SoundMaker::add_sample( int channel_1, int channel_2 ) {
	this->put_bits( this->file, channel_1, 2 );
	this->put_bits( this->file, channel_2, 2 );
}

