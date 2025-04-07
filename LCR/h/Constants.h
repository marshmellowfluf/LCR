#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iostream>
using namespace std;

const char TRANS_CHAR = '\0';
const string TRANS_CHAR_REP = " ";
const char BLACK_CHAR = '\1';
const string BLACK_CHAR_REP = "\033[47m \033[49m";
const char GREEN_CHAR = '\2';
const string GREEN_CHAR_REP = "\033[42m \033[49m";
const char PINK_CHAR = '\3';
const string PINK_CHAR_REP = "\033[45m \033[49m";
const char RED_CHAR = 4;
const string RED_CHAR_REP = "\033[41m \033[49m";
const char BLUE_CHAR = '\5';
const string BLUE_CHAR_REP = "\033[44m \033[49m";
const char YELLOW_CHAR = '\6';
const string YELLOW_CHAR_REP = "\033[103m \033[49m";
const char R_CHAR = '\7';
const string R_CHAR_REP = "\033[1;31mR\033[39m";
const char C_CHAR = 8;
const string C_CHAR_REP = "\033[1;34mC\033[39m";
const char L_CHAR = 9;
const string L_CHAR_REP = "\033[1;93mL\033[39m";
const char CYAN_CHAR = 17;
const string CYAN_CHAR_REP = "\033[46m \033[49m";

const int CHARACTER_SIZE = 2;  // Number of pixels per character
const int CHARACTER_WIDTH = 1;  // Number of pixels wide per character
const int CHARACTER_HEIGHT = 2;  // Number of pixels tall per character

const int MAX_COLORS = 7;
const char COLORS[7] = { BLACK_CHAR, RED_CHAR, BLUE_CHAR, YELLOW_CHAR, GREEN_CHAR, PINK_CHAR, CYAN_CHAR };

const string NAME_DICTIONARY[] = {"James", "Mary", "Michael", "Patricia", "Robert", "Jennifer", "John", "Linda", "David", "Elizabeth", "William", "Barbara", "Richard", "Susan", "Joseph", "Jessica", "Thomas", "Karen", "Christopher", "Sarah", "Charles", "Lisa", "Daniel", "Nancy", "Matthew", "Sandra", "Anthony", "Betty", "Mark", "Ashley", "Donald", "Emily", "Steven", "Kimberly", "Andrew", "Margaret", "Paul", "Donna", "Joshua", "Michelle", "Kenneth", "Carol", "Kevin", "Amanda", "Brian", "Melissa", "Timothy", "Deborah", "Ronald", "Stephanie", "George", "Rebecca", "Jason", "Sharon", "Edward", "Laura", "Jeffrey", "Cynthia", "Ryan", "Dorothy", "Jacob", "Amy", "Nicholas", "Kathleen", "Gary", "Angela", "Eric", "Shirley", "Jonathan", "Emma", "Stephen", "Brenda", "Larry", "Pamela", "Justin", "Nicole", "Scott", "Anna", "Brandon", "Samantha", "Benjamin", "Katherine", "Samuel", "Christine", "Gregory", "Debra", "Alexander", "Rachel", "Patrick", "Carolyn", "Frank", "Janet", "Raymond", "Maria", "Jack", "Olivia", "Dennis", "Heather", "Jerry", "Helen", "Tyler", "Catherine", "Aaron", "Diane", "Jose", "Julie", "Adam", "Victoria", "Nathan", "Joyce", "Henry", "Lauren", "Zachary", "Kelly", "Douglas", "Christina", "Peter", "Ruth", "Kyle", "Joan", "Noah", "Virginia", "Ethan", "Judith", "Jeremy", "Evelyn", "Christian", "Hannah", "Walter", "Andrea", "Keith", "Megan", "Austin", "Cheryl", "Roger", "Jacqueline", "Terry", "Madison", "Sean", "Teresa", "Gerald", "Abigail", "Carl", "Sophia", "Dylan", "Martha", "Harold", "Sara", "Jordan", "Gloria", "Jesse", "Janice", "Bryan", "Kathryn", "Lawrence", "Ann", "Arthur", "Isabella", "Gabriel", "Judy", "Bruce", "Charlotte", "Logan", "Julia", "Billy", "Grace", "Joe", "Amber", "Alan", "Alice", "Juan", "Jean", "Elijah", "Denise", "Willie", "Frances", "Albert", "Danielle", "Wayne", "Marilyn", "Randy", "Natalie", "Mason", "Beverly", "Vincent", "Diana", "Liam", "Brittany", "Roy", "Theresa", "Bobby", "Kayla", "Caleb", "Alexis", "Bradley", "Doris", "Russell", "Lori", "Lucas", "Tiffany"};

const int SEAT_POSITIONS[10][4] = { {45, 18, 55, 19}, {18, 18, 28, 19}, {0, 12, 1, 17}, {0, 3, 1, 8}, {18, 0, 28, 1},
    {45, 0, 55, 1}, {72, 0, 82, 1}, {98, 3, 99, 8}, {98, 12, 99, 17}, {72, 18, 82, 19} };
const int CHIPS_POSITIONS[10][2] = { {45, 16}, {18, 16}, {3, 13}, {3, 4}, {18, 4}, {45, 4}, {72, 4}, {87, 4}, {87, 13}, {72, 16} };
const int NAMES_POSITIONS[10][2] = { {45, 15}, {18, 15}, {3, 12}, {3, 3}, {18, 3}, {45, 3}, {72, 3}, {87, 3}, {87, 12}, {72, 15} };
const int DICE_POSITIONS[10][2] = { {45, 17}, {18, 17}, {3, 14}, {3, 5}, {18, 5}, {45, 5}, {72, 5}, {87, 5}, {87, 14}, {72, 17} };
const int CENTER_CHIPS_POSITION[2] = {42, 10};

#endif