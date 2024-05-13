#include "mainwindow.h"
#include "game.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include "CustomLabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , deck()
    , game("PLAYER", "CPU", deck)
    , swappings()
    , swaps(3)
    , aiswaps(3)
    , round(1)
    , debugMode(false)
    , aiKnownDeck(52)
    , swapped(false)
    , swapsleft(0)

{
    //Connect UI elements
    ui->setupUi(this);
    connect(ui->PlayButton, SIGNAL(clicked(bool)), this, SLOT(onPlayClicked()));
    connect(ui->Restart, SIGNAL(clicked(bool)), this, SLOT(onRestartClicked()));
    connect(ui->swapCard, &QPushButton::clicked, this, &MainWindow::onSwapClicked);
    connect(ui->sortByGroup, &QPushButton::clicked, this, &MainWindow::onSortByGroup);
    connect(ui->sortByValue, &QPushButton::clicked, this, &MainWindow::onSortByValue);
    connect(ui->next, &QPushButton::clicked, this, &MainWindow::onNextClicked);
    connect(ui->skip, &QPushButton::clicked, this, &MainWindow::onSkipClicked);
    ui->GameControls->hide();
    ui->Results->hide();
    ui->display->hide();

}

MainWindow::~MainWindow()
{
    delete ui;
}
// Render the player's hand (Seperate than CPU because we need to be able to click on player's cards)
void MainWindow::renderCards(Player player)
{
    qDebug() << "Rendering cards!";
    Hand playerHand = player.getHand();

    QVector<QLabel*> playerCardLabels;

    for (int i = 0; i < playerHand.getCards().size(); ++i)
    {
        CustomLabel* playerCardLabel = new CustomLabel(this);
        ui->PlayerCards->addWidget(playerCardLabel);
        playerCardLabels.append(playerCardLabel);

        QString filename = playerHand.getCards()[i].getFileName();
        QPixmap pixmap(filename);
        playerCardLabel->setPixmap(pixmap);
        playerCardLabel->setScaledContents(true); // Set scaledContents to true
        playerCardLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored); // Set size policy

        Card card = playerHand.getCards()[i];

        connect(playerCardLabel, &CustomLabel::cardClicked, this, [=]() { onCardClicked(card, playerCardLabel); });


    }

}

void MainWindow::renderCards()
{
    Hand CPUHand = game.getPlayer2().getHand();

    QVector<QLabel*> CPUCardLabels;

    for (int i = 0; i < CPUHand.getCards().size(); ++i)
    {
        CustomLabel* CPUCardLabel = new CustomLabel(this);
        ui->CPUCards->addWidget(CPUCardLabel);
        CPUCardLabels.append(CPUCardLabel);

        QString filename;

        if (ui->DeBugMode->isChecked())
        {
            filename = CPUHand.getCards()[i].getFileName();

        }else if(debugMode)
        {
            filename = CPUHand.getCards()[i].getFileName();
        }
        else
        {
            filename = ":/PNG-cards-1.3/back.png";
        }
        QPixmap pixmap(filename);

        CPUCardLabel->setPixmap(pixmap);
        CPUCardLabel->setScaledContents(true); // Set scaledContents to true
        CPUCardLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored); // Set size policy

        if (ui->DeBugMode->isChecked()){
            Card card = CPUHand.getCards()[i];

            connect(CPUCardLabel, &CustomLabel::cardClicked, this, [=]() { onCardClicked(card, CPUCardLabel); });
        }

    }
}
// PlayRound
void MainWindow::onNextClicked()
{

    if (swapped){

        //Have ai calculate the possibility of getting better hand upon a swap
        for (Card i : game.getPlayer2P()->getHand().getCards()){
            aiKnownDeck.append(i);
        }

        QString aiBest = game.getPlayer2P()->getHandP()->getBest();

        QVector<Card> aiCards = game.getPlayer2P()->getHandP()->getCards();

        QVector<int> aiswappings;
        // All possible cards
        QVector<Card> allCards;
        for (int suit = 0; suit < 4; ++suit) {
            for (int rank = 2; rank <= 14; ++rank) {
                allCards.append(Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)));
            }
        }
        // Make a vector of all unseen cards
        QVector<Card> unseenCards = allCards;
        for (const Card& knownCard : aiKnownDeck) {
            for (int i = 0; i < unseenCards.size(); ++i) {
                if (unseenCards[i].getFileName() == knownCard.getFileName()) {
                    unseenCards.remove(i);
                    break;
                }
            }
        }

        // Iterate over each card in the AI's hand
        for (int i = 0; i < aiCards.size(); ++i) {
            Card originalCard = aiCards[i];

            // Keep track of the best card to swap and its improvement probability
            Card bestSwapCard = originalCard;
            double bestImprovementProbability = 0.0;

            // Iterate over each unseen card
            for (const Card& unseenCard : unseenCards) {
                aiCards[i] = unseenCard;

                // Calculate the new best hand and its value
                Hand tempHand;
                tempHand.setHand(aiCards);
                QString newBest = tempHand.getBest();

                int newValue = 0;

                for (Card i : tempHand.getCards()){
                    newValue += i.getValue();
                }


                double improvementProbability = newValue /  202.0; // constant value to divide the total value by. I've come this this by testing I didn't use any mathematical calculation to come to this number

                // If the improvement probability is better, update the best swap card
                if (improvementProbability > bestImprovementProbability) {
                    bestSwapCard = unseenCard;
                    bestImprovementProbability = improvementProbability;
                }
            }

            if (bestImprovementProbability > 0.25 && aiswaps > 0 && swapsleft > 0) {
                qDebug() << "AI SWAP";
                aiswappings.append(i);
                game.getPlayer2P()->swapCards(aiswappings, deck);
                aiswaps--;
                swapsleft--;
            }

            aiCards[i] = originalCard;
        }


    }

    if (round == 4){
        swaps = 0;
        aiswaps = 0;
        QString swapText = QString("SWAPS: %1").arg(swaps);
        ui->swapsLeft->setText(swapText);
    }
    if (round < 6){
        QString swapText = QString("ROUND: %1").arg(round);
        ui->roundCount->setText(swapText);

        round++;
        if (round != 6){
            QString swapText = QString("ROUND: %1").arg(round);
            ui->round->setText(swapText);
        }

        debugMode = true;
        clearLayout(ui->PlayerCards->layout());
        clearLayout(ui->CPUCards->layout());
        renderCards(game.getPlayer1());
        renderCards();

        debugMode = false;
        ui->roundInfo->setText(game.playRound());
        ui->GameControls->hide();
        ui->display->show();
        QString score = "CPU SCORE: " + QString::number(game.getPlayer2().getScore());
        ui->cpuScore_2->setText(score);
        score = "PLAYER SCORE: " + QString::number(game.getPlayer1().getScore());
        ui->playerScore_2->setText(score);
    }
}

// On round result display once clicked skip to proceed to the next round
void MainWindow::onSkipClicked()
{
    swapped= false;
    for (Card i : game.getPlayer1P()->getHand().getCards()){
        aiKnownDeck.append(i);
    }


    QVector<Card> emptyHand(5);
    game.getPlayer1().getHandP()->setHand(emptyHand);
    game.getPlayer2().getHandP()->setHand(emptyHand);
    game.dealCards();
    clearLayout(ui->PlayerCards->layout());
    clearLayout(ui->CPUCards->layout());
    renderCards(game.getPlayer1());
    renderCards();
    ui->GameControls->show();
    ui->display->hide();

    if (round == 6){
        ui->GameControls->hide();
        ui->display->show();
        ui->skip->hide();
        clearLayout(ui->PlayerCards->layout());
        clearLayout(ui->CPUCards->layout());
        ui->Controls->show();
        ui->Results->show();

        if (game.getPlayer1().getScore() > game.getPlayer2().getScore()){
            QString win = game.getPlayer1().getName() + " WINS";
            ui->winner->setText(win);
        }
        else if (game.getPlayer2().getScore() > game.getPlayer1().getScore()){
            QString win = game.getPlayer2().getName() + " WINS";
            ui->winner->setText(win);
        }
        else
        {
            ui->winner->setText("TIE");
        }

        QString score = "CPU SCORE: " + QString::number(game.getPlayer2().getScore());
        ui->cpuScore->setText(score);
        score = "PLAYER SCORE: " + QString::number(game.getPlayer1().getScore());
        ui->playerScore->setText(score);
    }
}
// main play button
void MainWindow::onPlayClicked()
{
    swaps = 3;
    aiswaps = 3;
    round = 1;
    game.getDeck()->resetIndex();
    game.getDeck()->shuffle();
    game.getPlayer1P()->resetScore();
    game.getPlayer2P()->resetScore();
    QString swapText = QString("ROUND: %1").arg(round);
    ui->round->setText(swapText);
    swapText = QString("SWAPS: %1").arg(swaps);
    ui->swapsLeft->setText(swapText);
    ui->Results->hide();
    qDebug() << "Play Clicked";
    game.dealCards();

    renderCards(game.getPlayer1());
    renderCards();

    ui->Controls->hide();
    ui->GameControls->show();
    ui->display->hide();
    ui->skip->show();

}
// Adding clickability to cards and handling swap vector
void MainWindow::onCardClicked(Card card, CustomLabel *const label)
{
    qDebug() << "Card clicked!";

    qDebug() << card.getSuit();
    qDebug() << card.getValue();

    Hand playerHand = game.getPlayer1().getHand();
    QVector<Card> cards = playerHand.getCards();

    // Find the index of the clicked card in the player's hand
    int cardIndex = -1;
    for (int i = 0; i < cards.size(); ++i) {
        if (cards[i].getName() == card.getName()) {
            cardIndex = i;
            break;
        }
    }

    // If the card was found and is not already in swappings, add it
    if (cardIndex != -1 && !swappings.contains(cardIndex)) {
        if (swappings.size() < swaps) {
            swappings.append(cardIndex);
            label->setHighlighted(true);
        }
    } else if (swappings.contains(cardIndex)) {
        // If the card is already in swappings, remove it
        swappings.removeAll(cardIndex);
        label->setHighlighted(false);
    }

}
// Once clicked swap, call the function with the vector
void MainWindow::onSwapClicked(){
    swapped= true;
    qDebug() << "Swap clicked!";

    if ((swaps - swappings.size()) >= 0){

        swapsleft += swappings.size();
        swaps -= swappings.size();

        QString swapText = QString("SWAPS: %1").arg(swaps);
        ui->swapsLeft->setText(swapText);
        QVector<Card> test = game.getPlayer1P()->getHandP()->swapCard(swappings, deck);

        game.getPlayer1P()->getHandP()->setHand(test);

        swappings.clear();
        clearLayout(ui->PlayerCards->layout());
        clearLayout(ui->CPUCards->layout());

        qDebug() << game.getPlayer1().getHand().getCards()[0].getSuit();

        int count = 0;
        for (Card index : test)
        {
            qDebug() << game.getPlayer1P()->getHandP()->getCards()[count].getFileName();
            count++;
        }


        renderCards(game.getPlayer1());
        renderCards();

    }
}

void MainWindow::onSortByGroup(){
    qDebug() << "Sort By Group clicked!";

    game.getPlayer1P()->getHandP()->sortGroup();
    clearLayout(ui->PlayerCards->layout());
    clearLayout(ui->CPUCards->layout());

    renderCards(game.getPlayer1());
    renderCards();
}

void MainWindow::onSortByValue(){
    qDebug() << "Sort By Value clicked!";

    game.getPlayer1P()->getHandP()->sortValue();
    clearLayout(ui->PlayerCards->layout());
    clearLayout(ui->CPUCards->layout());

    renderCards(game.getPlayer1());
    renderCards();
}

void MainWindow::onRestartClicked()
{
    qDebug() << "Restart Clicked";

    ui->Controls->show();
    ui->GameControls->hide();

    clearLayout(ui->PlayerCards->layout());
    clearLayout(ui->CPUCards->layout());
    swaps = 3;
    QString swapText = QString("SWAPS: %1").arg(swaps);
    ui->swapsLeft->setText(swapText);
    round = 1;
    swapText = QString("ROUND: %1").arg(round);
    ui->round->setText(swapText);
    swappings.clear();
    Deck newDeck;
    game = Game("Player", "CPU", newDeck);

}

void MainWindow::clearLayout(QLayout *layout) {
    if (!layout)
        return;

    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            delete widget;
        } else if (QLayout* childLayout = item->layout()) {
            clearLayout(childLayout);
        }
        delete item;
    }
}

