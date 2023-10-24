#ifndef DECOR_H
#define DECOR_H

// ========================

void icon();
void logo();
void hLine();
void hLine_thin();
void title(char *title);
void header(char *text);
void hideCursor();
void showCursor();
void moveCursor(int x, int y);
void textWhite();
void textGreen();
void textRed();
void textBlue();
void textYellow();
void alert(char *message, float time);
void success(char *message, float time);
void command(char *command);
void stripNewLine(char *str);
void clearBuffer();

// ========================

#endif // DECOR_H