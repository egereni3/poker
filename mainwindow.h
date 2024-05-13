#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Card.h>
#include <Game.h>
#include <customlabel.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onNextClicked();
    void onPlayClicked();
    void onSkipClicked();
    void onCardClicked(Card card, CustomLabel *const label);
    void onRestartClicked();
    void clearLayout(QLayout *layout);
    void renderCards();
    void renderCards(Player player);
    void onSwapClicked();
    void onSortByValue();
    void onSortByGroup();


private:
    Ui::MainWindow *ui;
    bool debugMode;
    Deck deck;
    Game game;
    int round;
    QVector<int> swappings;
    int swaps;
    int aiswaps;
    QVector<Card> aiKnownDeck;
    bool swapped;
    int swapsleft;
};
#endif // MAINWINDOW_H
