#include <iostream>

class Student {
	private:
		int scores[5];
	public:
		void input() {
			for (int i = 0; i < 5; i++) {
				int score;
				
				std::cin >> score;
				scores[i] = score;
			}
		}
		int calc_total_score() {
			int sum = 0;
			
			for (int i = 0; i < 5; i++) {
				sum += scores[i];
			}

			return sum;
		}
};

int main() {
	int no_of_students;
	
	std::cin >> no_of_students;

	Student* s = new Student[no_of_students];

	s[0].input();
	int kristen_total_score = s[0].calc_total_score();
	int no_of_highscores = 0;

	for (int i = 1; i < no_of_students; i++) {
		s[i].input();
		int total_score = s[i].calc_total_score();

		if (total_score > kristen_total_score) {
			no_of_highscores++;
		}
	}

	std::cout << no_of_highscores;
}