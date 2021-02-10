#include "mainwindow.h"

MainWindow::MainWindow()
{
    setWindowTitle("Drag and drop from QListWidget v1");
    resize(350,250);

    createListWidget();
    createSceneAndView();
    createGraphicsItems();
    createLayout();
}

void MainWindow::createListWidget(){
    itemListWidget = new QListWidget;
    QStringList itemList;
    itemList << "gray" << "blue" << "orange";
    itemListWidget->addItems(itemList);
    itemListWidget->setFixedWidth(100);
    itemListWidget->setDragEnabled(true);
}

void MainWindow::createSceneAndView(){
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,200,200);
    view = new QGraphicsView;
    view->setScene(scene);
}

void MainWindow::createGraphicsItems(){
    QRectF rect(0,0,70,40);

    CustomRectItem *rItem1 = new CustomRectItem;
    scene->addItem(rItem1);
    rItem1->setRect(rect);
    rItem1->setPos(20,20);
    rItem1->setBrush(QColor("#FF8C69"));

    CustomRectItem *rItem2 = new CustomRectItem;
    scene->addItem(rItem2);
    rItem2->setRect(rect);
    rItem2->setPos(20,80);
    rItem2->setBrush(QColor("#C0C0C0"));

    CustomRectItem *rItem3 = new CustomRectItem;
    scene->addItem(rItem3);
    rItem3->setRect(rect);
    rItem3->setPos(20,140);
    rItem3->setBrush(QColor("#87CEEB"));

    CustomRectItem *rItem4 = new CustomRectItem;
    scene->addItem(rItem4);
    rItem4->setRect(rect);
    rItem4->setPos(110,20);
    rItem4->setBrush(QColor("#DCDCDC"));

    CustomRectItem *rItem5 = new CustomRectItem;
    scene->addItem(rItem5);
    rItem5->setRect(rect);
    rItem5->setPos(110,80);
    rItem5->setBrush(QColor("#1E90FF"));

    CustomRectItem *rItem6 = new CustomRectItem;
    scene->addItem(rItem6);
    rItem6->setRect(rect);
    rItem6->setPos(110,140);
    rItem6->setBrush(QColor("#FF6600"));
}

void MainWindow::createLayout(){
    QFrame *frame = new QFrame;
    QHBoxLayout *frameLayout = new QHBoxLayout(frame);
    frameLayout->addWidget(itemListWidget);
    frameLayout->addWidget(view);
    setCentralWidget(frame);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Delete){
        foreach(QGraphicsItem *item, scene->selectedItems())
            if(CustomRectItem *rItem = qgraphicsitem_cast<CustomRectItem*> (item))
                rItem->setText(QString());
        scene->clearSelection();
    }
    QMainWindow::keyPressEvent(event);
}
