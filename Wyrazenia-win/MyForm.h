#pragma once
#include <cstdio>
#include <iostream>
#include <windows.h>
#include <vector>
#include <map>


namespace AlgorytmGen {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	bool cmp = false;
	struct gene
	{ 
		double X, Y; 
		bool operator()(const double& a, const double& b) const
		{
			return cmp ? a > b : a < b;
		}
	};
	/*
	struct double_cmp 
	{
		bool operator()(const double& a, const double& b) const
		{
			return a > b;
		}
	};
	*/
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:
	private: System::Windows::Forms::Label^  l_result;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  b_Start;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::CheckBox^  checkBoxMax;


	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->l_result = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->b_Start = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->checkBoxMax = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// l_result
			// 
			this->l_result->AutoSize = true;
			this->l_result->Location = System::Drawing::Point(16, 231);
			this->l_result->Name = L"l_result";
			this->l_result->Size = System::Drawing::Size(0, 13);
			this->l_result->TabIndex = 10;
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(10, 66);
			this->chart1->Margin = System::Windows::Forms::Padding(2);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SemiTransparent;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Algorytm genetyczny";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->IsXValueIndexed = true;
			series2->Legend = L"Legend1";
			series2->Name = L"Potomki";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(1011, 521);
			this->chart1->TabIndex = 11;
			this->chart1->Text = L"chart1";
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// b_Start
			// 
			this->b_Start->Location = System::Drawing::Point(338, 11);
			this->b_Start->Margin = System::Windows::Forms::Padding(2);
			this->b_Start->Name = L"b_Start";
			this->b_Start->Size = System::Drawing::Size(62, 24);
			this->b_Start->TabIndex = 12;
			this->b_Start->Text = L"Start";
			this->b_Start->UseVisualStyleBackColor = true;
			this->b_Start->Click += gcnew System::EventHandler(this, &MyForm::b_Start_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(416, 16);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 8);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(183, 26);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Aplikacja wyszukuj¹ca optimum \r\nza pomoc¹ algortytmu genetycznego.";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(193, 7);
			this->radioButton1->Margin = System::Windows::Forms::Padding(2);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(130, 17);
			this->radioButton1->TabIndex = 15;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Funkcja Michalewicza";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(193, 26);
			this->radioButton2->Margin = System::Windows::Forms::Padding(2);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(113, 17);
			this->radioButton2->TabIndex = 16;
			this->radioButton2->Text = L"Funkcja Rastrigina";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(193, 45);
			this->radioButton3->Margin = System::Windows::Forms::Padding(2);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(116, 17);
			this->radioButton3->TabIndex = 17;
			this->radioButton3->Text = L"Funkcja Schwefela";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// checkBoxMax
			// 
			this->checkBoxMax->AutoSize = true;
			this->checkBoxMax->Location = System::Drawing::Point(45, 37);
			this->checkBoxMax->Name = L"checkBoxMax";
			this->checkBoxMax->Size = System::Drawing::Size(46, 17);
			this->checkBoxMax->TabIndex = 18;
			this->checkBoxMax->Text = L"Max";
			this->checkBoxMax->UseVisualStyleBackColor = true;
			this->checkBoxMax->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBoxMax_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(986, 598);
			this->Controls->Add(this->checkBoxMax);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->b_Start);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->l_result);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Algorytm genetyczny";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//---------------------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------------------------
																								const int MaxIter = 1000;
																								const int MAXPOP = 50;
																								const long double Epsilon = pow(10, -12);// std::numeric_limits<double>::epsilon();
																								const int mut = 4;//if (0 == Potomki.size() % mut) {...mut kod...} co 4-ty, to jest 25%
																								//---------------------------------------------
																								const double f_MinFM = 0;
																								const double f_MaxFM= 3.14159265358979323846;
																								const double f_MinFR = -5.12;
																								const double f_MaxFR = 5.12; 
																								const double f_MinFS = - 500;
																								const double f_MaxFS = 500;
																								const double Wspolczyjnik_zlotego_wydzia³u = (sqrt(5)-1) / 2;
																								const double Const_ans_MinWartosc = -10000;
																								const double Const_ans_MaxWartosc = 10000;																								
		//---------------------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------------------------

		double fRand(double fMin, double fMax)
		{
			double f = (double)rand() / RAND_MAX;
			return fMin + f * (fMax - fMin);
		};

		double FM(gene &g)//funkcja michalewicza
		{
			double Pi = 3.14159265358979323846;
			return -sin(g.X)*pow(sin(g.X*g.X / Pi), 20) - sin(g.Y)*pow(sin(2 * g.Y*g.Y / Pi), 20);
		};
		double FR(gene &g)//funkcja Rastrigina
		{
			double Pi = 3.14159265358979323846;
			return 20 + g.X*g.X - 10 * cos(2 * Pi*g.X) + g.Y*g.Y - 10 * cos(2 * Pi*g.Y);
		}
		double FS(gene &g)//funkcja Schwefela
		{
			return 2*418.9829 - g.X*sin(pow(abs(g.X), 0.5)) - g.Y*sin(pow(abs(g.Y), 0.5));
		}
		double f(gene &g)
		{
			return radioButton1->Checked ? FM(g) : radioButton2->Checked ? FR(g): FS(g);
		}

		double ans_MinWartosc;
		double ans_MinWartosc_X;
		double ans_MinWartosc_Y;

		double ans_MaxWartosc;
		double ans_MaxWartosc_X;
		double ans_MaxWartosc_Y;
		
		void Sumuj(map < double, gene, gene >& population, map <double, gene, gene >& potomki)
		{			
			map < double, gene, gene > tmp= population;
			tmp.insert(potomki.begin(), potomki.end());

			population.clear();
			{

			};
			for (auto it : tmp)
			{
				if (population.size() < MAXPOP)
					population.insert(it);
				else
					break;
			}


			if (ans_MinWartosc > (*population.begin()).first)
			{
				ans_MinWartosc = (*population.begin()).first;
				ans_MinWartosc_X = (*population.begin()).second.X;
				ans_MinWartosc_Y = (*population.begin()).second.Y;
			}

			if (ans_MaxWartosc < (*population.begin()).first)
			{
				ans_MaxWartosc = (*population.begin()).first;
				ans_MaxWartosc_X = (*population.begin()).second.X;
				ans_MaxWartosc_Y = (*population.begin()).second.Y;
			}

		}

	private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
	};
	private: System::Void b_Start_Click(System::Object^  sender, System::EventArgs^  e) {
		
		checkBoxMax->Checked ? cmp = true : cmp;
		

		
		map <  double, gene, gene > population;
		ans_MinWartosc = Const_ans_MaxWartosc;
		ans_MaxWartosc = Const_ans_MinWartosc;

		this->chart1->Series["Algorytm genetyczny"]->Points->Clear();
		this->chart1->Series["Potomki"]->Points->Clear();
		this->chart1->Series["Potomki"]->Color = Color::Blue;

		//--------------------------------------------------------------------------------------------------------pocz¹skowa populacja
		double min = radioButton1->Checked ? f_MinFM : radioButton2->Checked ? f_MinFR : f_MinFS;
		double max = radioButton1->Checked ? f_MaxFM : radioButton2->Checked ? f_MaxFR : f_MaxFS;

		while ( population.size() < MAXPOP )//przypisujemu losowa wartosc dla kazdego genu
		{
			gene g = { fRand(min, max), fRand(min, max) };
			population.insert(pair<double, gene >(f(g), g));
		}
		//--------------------------------------------------------------------------------------------------------------------
		
		//for (int iter = 0; true; ++iter)
		for (int iter = 0; iter < MaxIter; ++iter)
		{
			map < double, gene, gene > Potomki;

			while ( Potomki.size()<MAXPOP )
			{				
				auto it1 = population.begin();
				int tmp = rand() % MAXPOP;
				for  (int i = 0; i<tmp; ++i)
					++it1;

				auto it2 = population.begin();
				tmp = rand() % MAXPOP;
				for (int i = 0; i<tmp; ++i)
					++it2;
				
				gene g1 = (*it1).second, g2 = (*it2).second;
				gene Sum1, Sum2;
				Sum1.X = (g1.X + g2.X) / 2;
				Sum1.Y = (g1.Y + g2.Y) / 2;

				Sum2.X =		Wspolczyjnik_zlotego_wydzia³u *		g1.X + (1 - Wspolczyjnik_zlotego_wydzia³u)*	g2.X;
				Sum2.Y = (1- Wspolczyjnik_zlotego_wydzia³u)	  *		g1.Y +		Wspolczyjnik_zlotego_wydzia³u *	g2.Y;
				
				if (0 != Potomki.size() % mut) // dla (100/mut)%
				{
					Potomki.insert(pair<double, gene>(f(Sum1), Sum2));
					Potomki.insert(pair<double, gene>(f(Sum2), Sum2));
				}
				else//mutation for ?% potomków
				{
					gene g1 = { fRand(min, max), fRand(min, max) }, g2 = { fRand(min, max), fRand(min, max) };

					Potomki.insert(pair<double, gene>(f(g1), g1));
					Potomki.insert(pair<double, gene>(f(g2), g2));
				}
				

				if (g1.X != g2.X && g1.Y != g2.Y &&sqrt((g1.X - g2.X)*(g1.X - g2.X) + (g1.Y - g2.Y)*(g1.Y - g2.Y)) < Epsilon)
					goto END;

			}

			Sumuj(population, Potomki);//Sumuj zmieniaj¹c populacjê pó³owê najlepszych//size()/2 ////// A+B i Wybiera (A+B)/2 najlepszych

			//this->chart1->Series["Potomki"]->Points->AddXY(iter, (Potomki.begin())->first);	
			this->chart1->Series["Algorytm genetyczny"]->Points->AddXY(iter, (population.begin())->first);
		}

END:	label1->Text = "f(x*) = " + ans_MinWartosc + ",\ndla x* = (" + ans_MinWartosc_X + ",\n" + ans_MinWartosc_Y + ")";
	}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (radioButton1->Checked == true)
	{
		radioButton2->Checked = false;
		radioButton3->Checked = false;
	}
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (radioButton2->Checked == true)
	{
		radioButton1->Checked = false;
		radioButton3->Checked = false;
	}
}
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (radioButton3->Checked == true)
	{
		radioButton2->Checked = false;
		radioButton1->Checked = false;
	}
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkBoxMax_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
