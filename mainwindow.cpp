#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLayout>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi( this);
    initToolbar();

    initMainArea();
    initIcons();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initToolbar()
{

    QSize myIconSize(32,32);
    ui->mainToolBar->setIconSize( myIconSize );

    //����ĵ���ť,������׵������˵�
    add_doc_button = new QToolButton( this );
    add_doc_button->setDefaultAction( ui->menu_action_add_file );

    QMenu * buttonMenu = new QMenu( this );
    buttonMenu->addAction( ui->menu_action_add_file );
    buttonMenu->addAction( ui->menu_action_add_category );
    buttonMenu->addAction( ui->menu_action_manual_input );
    add_doc_button->setMenu( buttonMenu );
    add_doc_button->setPopupMode( QToolButton::MenuButtonPopup );
    ui->mainToolBar->addWidget( add_doc_button );

    //ɾ���ĵ���ť
    del_doc_button = new QToolButton( this );
    del_doc_button->setDefaultAction( ui->menu_action_remove_file );
    ui->mainToolBar->addWidget( del_doc_button );

    //�������ఴť
    create_category_button = new QToolButton( this );
    create_category_button->setDefaultAction( ui->menu_action_add_category );
    ui->mainToolBar->addWidget( create_category_button );

    //�Ƴ����ఴť
    remove_category_button = new QToolButton( this );
    remove_category_button->setDefaultAction( ui->menu_action_remove_category );
    ui->mainToolBar->addWidget( remove_category_button );

    //������
    QWidget* spacer = new QWidget( this );

    spacer->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
    ui->mainToolBar->addWidget( spacer );
    searchSquare = new QLineEdit( this );
    searchSquare->setText(tr("enter word to search"));

    searchSquare->setSizePolicy( QSizePolicy::Fixed,QSizePolicy::Fixed );
    ui->mainToolBar->addWidget( searchSquare );
    QWidget* spacer2 = new QWidget( this );

    spacer2->setSizePolicy( QSizePolicy::Fixed,QSizePolicy::Expanding );
    ui->mainToolBar->addWidget( spacer2 );
    initToolbarStyle();

}

void MainWindow::initToolbarStyle()
{
    add_doc_button->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
    del_doc_button->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
    create_category_button->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
    remove_category_button->setToolButtonStyle( Qt::ToolButtonTextUnderIcon );
}

void MainWindow::initIcons()
{
    //������ͼ���ʼ��
    QIcon add_doc_icon(":/toolbaricon/img/file_add.png");
    add_doc_button->setIcon( add_doc_icon );
    QIcon del_doc_icon(":/toolbaricon/img/file_delete.png");
    del_doc_button->setIcon( del_doc_icon );
    QIcon create_category_icon(":/toolbaricon/img/folder_add.png");
    create_category_button->setIcon( create_category_icon );
    QIcon remove_category_icon(":/toolbaricon/img/folder_delete.png");
    remove_category_button->setIcon( remove_category_icon );
    //�˵�ͼ���ʼ��
}

void MainWindow::initMainArea()
{

    ui->mainToolBar->setMovable( false );
    //��������������Ϊgridlayout��������������������
    ui->centralWidget->setLayout( ui->horizontalLayout );
}
