// Created by coolq

String code = "+++++ [ > + < - ]"; 
int cells[] = {0,0,0,0,0,0,0,0};

int cellpointer = 0;
int codepointer = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("Serial Connected...");
}

void loop() {
  // put your main code here, to run repeatedly:
  int c = code.length();
  while (codepointer <= c)
  {
    boolean isPlus = (code[codepointer] == '+');
    boolean isMinus = (code[codepointer] == '-');
    boolean isLeft = (code[codepointer] == '<');
    boolean isRight = (code[codepointer] == '>');
    boolean isLeftBracket = (code[codepointer] == '[');
    boolean isRightBracket = (code[codepointer] == ']');

    if (isPlus) {
      Serial.println("Add            |+|");
      cells[cellpointer]++;
    }
    if (isMinus) {
      Serial.println("Subtract       |-|");
      cells[cellpointer]--;
    }
    if (isLeft) {
      Serial.println("Left           |<|");
      cellpointer--;
    }
    if (isRight) {
      Serial.println("Right          |>|");
      cellpointer++;
    }
    if (isLeftBracket) {
      if (cells[cellpointer] == 0) {
        while (code[codepointer] != ']' && codepointer <= c) {
          codepointer++;
        }
        codepointer--;
      }
    }
    if (isRightBracket) {
      if (cells[cellpointer] != 0) {
        while (code[codepointer] != '[' && codepointer > 0) {
          codepointer--;
        }
      }
    }
    
    codepointer++;
  }
  
  Serial.print("No. Cells: ");
  Serial.println(sizeof(cells)/sizeof(int));
  for (int i = 0; i < sizeof(cells)/sizeof(int); i++) {
    Serial.print("[");
    Serial.print(cells[i]);
    Serial.print("]");
    if (i < sizeof(cells)/sizeof(int)-1) {
      Serial.print(", ");
    }
  }
  Serial.println();
  Serial.end();
}
