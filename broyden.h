#pragma once

#include <vector>
#include <stdio.h>
#include <math.h>

#include "extra.h"
#include <functional>
using namespace std;

//���������� ������ ��������
using func_2d = function<double(vect_2d)>;
using grad_f = function<vect_2d(vect_2d)>;


class Broyden {
public:
	void init(func_2d set_f, grad_f set_g, double set_eps, int set_iter); //��������� ����������� �������, � ��������� � ��������
	void minimization(vect_2d x0, vect_2d& x_m); //����������� �������, x0 - ��������� �����, x_m - ����� ��������

private:
	func_2d min_f; //��������������� �������
	grad_f min_f_grad;
	long int calc_count; //���������� ���������� �������
	double meth_eps; //��������� ������
	int max_iter; //������������ ����� ��������

	vect_2d x_k; //����������� �� ��������� ��������
	vect_2d grad_f_k; //�������� �� ���������� ��������
	matrix_2d etta_k; //����������� ������� ����� �� ���������� ��������

	double Fib(double a, double b); // ������������ ���������� ����� ������ - ����� ���������
	void find_area(double x0, double& a, double& b); // ������������ ����� ��� ����������� ������� ����������� ��������
	double one_min_f(double lambda); // ������� ��� ���������� �����������

};