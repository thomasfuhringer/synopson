#include <QIcon>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLabel>
#include <QAbstractItemView>
#include <QLabel>
#include <QDateTime>
#include "Pane.h"
#include "Properties.h"
#include "MainWindow.h"

Properties::Properties(QWidget *parent) : QDialog(parent)
{
    setWindowTitle(tr("Properties"));
    setWindowIcon(QIcon(":/Images/Properties.ico"));

    QVBoxLayout* layout = new QVBoxLayout(this);
    QFormLayout* formLayout = new QFormLayout();
    formLayout->setMargin(5);

    MainWindow* mainWindow(static_cast<MainWindow*>(parent));
    QWidget* focus(mainWindow->focusWidget());
    QAbstractItemView* view;
    if (focus == mainWindow->directoryTreeView || focus == mainWindow->leftPane->treeView || focus == mainWindow->leftPane->listView || focus == mainWindow->rightPane->treeView || focus == mainWindow->rightPane->listView){
        view =  qobject_cast<QAbstractItemView *>(focus);
        QFileInfo fileInfo = mainWindow->fileSystemModel->fileInfo(view->selectionModel()->selectedIndexes().at(0));
        QLabel* nLabel = new QLabel(fileInfo.fileName());
        formLayout->addRow(tr("Name:"), nLabel);
        QLabel* pLabel = new QLabel(fileInfo.path());
        formLayout->addRow(tr("Path:"), pLabel);
        QLabel* sLabel = new QLabel(QString::number(fileInfo.size()) + " byte");
        formLayout->addRow(tr("Size:"), sLabel);
        QLabel* cLabel = new QLabel(fileInfo.created().toString());
        formLayout->addRow(tr("Created:"), cLabel);
        QLabel* mLabel = new QLabel(fileInfo.lastModified().toString());
        formLayout->addRow(tr("Last Modified:"), mLabel);
        QLabel* rLabel = new QLabel(fileInfo.lastRead().toString());
        formLayout->addRow(tr("Last Read:"), rLabel);
        QLabel* oLabel = new QLabel(fileInfo.owner());
        formLayout->addRow(tr("Owner:"), oLabel);
        QLabel* gLabel = new QLabel(fileInfo.group());
        formLayout->addRow(tr("Group:"), gLabel);
    }

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    layout->addLayout(formLayout);
    layout->addWidget(buttonBox);
    setLayout(layout);
}

void Properties::accept()
{
    done(1);
}

// As yet unused
void Properties::reject()
{
    done(0);
}
