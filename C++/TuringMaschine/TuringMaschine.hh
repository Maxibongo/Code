#ifndef TURINGMASCHINE_HH
#define TURINGMASCHINE_HH

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cassert>


template<int band_size>
class TuringMaschine{
public:
	struct Instruction{
		std::vector<std::string> input_symbols;
		std::string input_state;
		std::string next_state;
		std::vector<std::string> written_symbols;
		std::vector<int> head_movements;

		Instruction();
		Instruction(std::string& input_state_, std::vector<std::string>& input_symbols_, std::string& next_state_,
			std::vector<std::string>& written_symbols_, std::vector<int>& head_movements_) : 
			input_state(input_state_),
			input_symbols(input_symbols_),
			next_state(next_state_),
			written_symbols(written_symbols_),
			head_movements(head_movements_)
			{
				assert (input_symbols.size() == written_symbols.size() && input_symbols.size() == band_size);
			};
	};
	TuringMaschine(std::string& input_alphabet_, std::string& band_alpahabet_,
		std::vector<Instruction>& instructions_, std::vector<std::string> accepting_states_,
		std::string& starting_state_):
		input_alphabet(input_alphabet_),
		band_alphabet(band_alpahabet_),
		instructions(instructions_),
		accepting_states(accepting_states_),
		starting_state(starting_state_)
		{
			band = std::vector<std::string>(band_size, "");
		};

	std::string run(std::string input_word, bool& accepting, int upper_limit = 1000){
		// run loop with word to process and check if is in language with an upper loop limit
		int counter = 0;
		std::vector<int> current_indices(band_size, 0);
		std::vector<std::string> current_symbols(band_size, " ");
		std::string current_state = starting_state;
		band[0] = input_word;

		current_symbols[0] = input_word[0];
		
		while(counter < upper_limit){
			int instruction_index = find_instruction(current_state, current_symbols);				
			if(instruction_index == -1){
				break;
			}
			process_instruction(current_state, current_symbols, instructions[instruction_index]);
			counter++;
		}
		if(std::find(accepting_states.begin(), accepting_states.end(), current_state)!=std::end(accepting_states))
			accepting = true;
		else
			accepting = false;
		return input_word;
	}

private:
	std::string input_alphabet;
	std::string band_alphabet;
	std::vector<Instruction> instructions;
	std::vector<std::string> accepting_states;
	std::string starting_state;
	std::vector<std::string> band;

	int find_instruction(std::string current_state, std::vector<std::string>& current_symbols){
		std::random_shuffle(instructions.begin(), instructions.end());
		for(int i = 0; i < instructions.size(); i++){
			for(int j = 0; j < instructions; j++){
				;
			}
		}
		return -1;
	}

	void process(std::string& current_state, std::vector<std::string>& current_symbols, Instruction instruction){

	}
};

#endif //TURINGMASCHINE_HH