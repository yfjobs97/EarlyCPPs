//HW 11b
//Course Grades
//Maximum score assumed for the exam is 100 points

#include <iostream>
#include <cstdlib>

using namespace std;

class GradedActivity
{
protected:
	double score;   // To hold the numeric score
public:
	// Default constructor
	GradedActivity()
	{
		score = 0.0;
	}

	// Constructor
	GradedActivity(double s)
	{
		score = s;
	}

	// Mutator function
	void setScore(double s)
	{
		score = s;
	}

	// Accessor functions
	double getScore() const
	{
		return score;
	}

	virtual char getLetterGrade() const;
};
char GradedActivity::getLetterGrade() const
{
	char letterGrade; // To hold the letter grade

	if (score > 89)
		letterGrade = 'A';
	else if (score > 79)
		letterGrade = 'B';
	else if (score > 69)
		letterGrade = 'C';
	else if (score > 59)
		letterGrade = 'D';
	else
		letterGrade = 'F';

	return letterGrade;
}

class PassFailActivity : public GradedActivity
{
protected:
	double minPassingScore;    // Minimum passing score.
public:
	// Default constructor
	PassFailActivity() : GradedActivity()
	{
		minPassingScore = 0.0;
	}

	// Constructor
	PassFailActivity(double mps) : GradedActivity()
	{
		minPassingScore = mps;
	}

	// Mutator
	void setMinPassingScore(double mps)
	{
		minPassingScore = mps;
	}

	// Accessors
	double getMinPassingScore() const
	{
		return minPassingScore;
	}

	virtual char getLetterGrade() const;
};
char PassFailActivity::getLetterGrade() const
{
	char letterGrade;

	if (score >= minPassingScore)
		letterGrade = 'P';
	else
		letterGrade = 'F';

	return letterGrade;
}

class PassFailExam : public PassFailActivity
{
private:
	int numQuestions;    // Number of questions
	double pointsEach;   // Points for each question
	int numMissed;       // Number of questions missed
public:
	// Default constructor
	PassFailExam() : PassFailActivity()
	{
		numQuestions = 0;
		pointsEach = 0.0;
		numMissed = 0;
	}

	// Constructor
	PassFailExam(int questions, int missed, double mps) :
		PassFailActivity(mps)
	{
		set(questions, missed);
	}

	// Mutator function
	void set(int, int); 

						 // Accessor functions
	double getNumQuestions() const
	{
		return numQuestions;
	}

	double getPointsEach() const
	{
		return pointsEach;
	}

	int getNumMissed() const
	{
		return numMissed;
	}
};
void PassFailExam::set(int questions, int missed)
{
	double numericScore;  // To hold the numeric score

						  // Set the number of questions and number missed.
	numQuestions = questions;
	numMissed = missed;

	// Calculate the points for each question.
	pointsEach = 100.0 / numQuestions;

	// Calculate the numeric score for this exam.
	numericScore = 100.0 - (missed * pointsEach);

	// Call the inherited setScore function to set
	// the numeric score.
	setScore(numericScore);
}

class FinalExam : public GradedActivity
{
private:
	int numQuestions;    // Number of questions
	double pointsEach;   // Points for each question
	int numMissed;       // Number of questions missed
public:
	// Default constructor
	FinalExam()
	{
		numQuestions = 0;
		pointsEach = 0.0;
		numMissed = 0;
	}

	// Constructor
	FinalExam(int questions, int missed)
	{
		set(questions, missed);
	}

	// Mutator functions
	void set(int, int);  
	void adjustScore();  

						 // Accessor functions
	double getNumQuestions() const
	{
		return numQuestions;
	}

	double getPointsEach() const
	{
		return pointsEach;
	}

	int getNumMissed() const
	{
		return numMissed;
	}
};
void FinalExam::set(int questions, int missed)
{
	double numericScore;  // To hold the numeric score

						  // Set the number of questions and number missed.
	numQuestions = questions;
	numMissed = missed;

	// Calculate the points for each question.
	pointsEach = 100.0 / numQuestions;

	// Calculate the numeric score for this exam.
	numericScore = 100.0 - (missed * pointsEach);

	// Call the inherited setScore function to set
	// the numeric score.
	setScore(numericScore);

	// Call the adjustScore function to adjust
	// the score.
	adjustScore();
}

//*****************************************************************
// Definition of Test::adjustScore. If score is within 0.5 points *
// of the next whole point, it rounds the score up and            *
// recalculates the letter grade.                                 *
//*****************************************************************

void FinalExam::adjustScore()
{
	double fraction = score - static_cast<int>(score);

	if (fraction >= 0.5)
	{
		// Adjust the score variable in the GradedActivity class.
		score += (1.0 - fraction);
	}
}

class CourseGrades
{
private:
	GradedActivity* grades[4];
public:
	void setLab(GradedActivity*);
	void setPassFailExam(PassFailExam*);
	void setEssay(GradedActivity*);
	void setPassFailExam(FinalExam*);
	void print();
};

//Settor Definitions
void CourseGrades::setLab(GradedActivity* Lab)
{
	grades[0] = Lab;	
}
void CourseGrades::setPassFailExam(PassFailExam* Exam)
{
	grades[1] = Exam;
}
void CourseGrades::setEssay(GradedActivity* Essay)
{
	grades[2] = Essay;	
}
void CourseGrades::setPassFailExam(FinalExam* Final)
{
	grades[3] = Final;
}
void CourseGrades::print()
{
	//Formatted Output

	cout << endl;
	cout << "Lab \t" << "Exam \t" << "Essay \t" << "Final \t" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << grades[i]->getScore() << "\t";
	}
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << grades[i]->getLetterGrade() << "\t";
	}
	cout << endl;
}


int main()
{
	double lab, essay, exam_p;
	int exam_q, exam_m, final_q, final_m;

	//Asking for data inputs
	cout << "Please input the grade for the lab: ";
	cin >> lab;
	cout << "Please input the number of questions in the exam: ";
	cin >> exam_q;

	//Input check
	while (exam_q < 0)
	{
		cout << "Number of questions cannot be negative.";
		cout << "Please input the number of questions in the exam:";
		cin >> exam_q;
	}

	cout << "Enter the questions missed in the exam: ";
	cin >> exam_m;
	
	//Input check
	while (exam_m < 0 || exam_m > exam_q)
	{
		cout << "INVALID Number input.";
		cout << "Enter the questions missed in the exam: ";
		cin >> exam_m;
	}

	cout << "Enter the minimum passing score of the exam: ";
	cin >> exam_p;

	//Input check
	while (exam_m < 0|| exam_m >100)
	{
		cout << "Number of passing score cannot be negative or greater than 100.";
		cout << "Please input the passing score of the exam: ";
		cin >> exam_q;
	}

	//Input check
	cout << "Enter the Essay Score: ";
	cin >> essay;
	cout << "Input the number of questions in the final: ";
	cin >> final_q;

	//Input check
	while (final_q < 0)
	{
		cout << "Number of questions cannot be negative.";
		cout << "Please input the number of questions in the final: ";
		cin >> final_q;
	}

	//Input check
	cout << "Input the questions missed in the final: ";
	cin >> final_m;

	//Input check
	while (final_m < 0 || final_m > final_q)
	{
		cout << "INVALID Number input.";
		cout << "Enter the questions missed in the final: ";
		cin >> final_m;
	}

	//Catagorizing inputs
	CourseGrades report;
	report.setLab( &(GradedActivity(lab)) );
	report.setPassFailExam(&(PassFailExam(exam_q, exam_m, exam_p)));
	report.setEssay(&(GradedActivity(essay)));
	report.setPassFailExam(&(FinalExam(final_q, final_m)));

	report.print();
	
	system("pause");
	return 0;
}
