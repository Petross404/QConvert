#include "qconvert.h"
#include "ui_qconvert.h"
#include "About/about.h"

QConvert::QConvert(QWidget* parent) :
	QMainWindow(parent),
	ui(new Ui::QConvert)
{
	ui->setupUi(this);
	setCentralWidget(ui->centralWidget);
	lst_CategoriesView = new QListView(this);
	lst_UnitsView_from = new QListView(this);
	lst_UnitsView_to = new QListView(this);
	strListModel_categories = new QStringListModel(this);
	strListModel_units_selection = new QStringListModel(this);
	comboboxCategories = new QComboBox(this);

	// Create GroupBoxes
	qgl_GridLayout = new QGridLayout;
	createUnitCategoriesList();
	qgl_GridLayout->addWidget(createUnitCategoriesGpBox(), 0, 0, 2, 1);
	qgl_GridLayout->addWidget(createUnitSelectionGpBox(), 0, 1, 1, 1);
	qgl_GridLayout->addWidget(createUnitConversionGpBox(), 1, 1, 1, 1);

	createActions();
	createMenus();

	this->resize(800, 500);
	ui->centralWidget->setLayout(qgl_GridLayout);
}

QConvert::~QConvert()
{
	delete ui;
}

QGroupBox* QConvert::createUnitCategoriesGpBox()
{
	qgb_GroupUnitCategories = new QGroupBox(tr("Unit Categories"));
	label_UnitCategory = new QLabel(tr(""), this);

	strListModel_categories = new QStringListModel();
	createUnitCategoriesList();
// 	connect(lst_CategoriesView, QOverload<void>::of(&QListView::update), this, QConvert::createUnitCategoriesList())

	grid_UnitCategories = new QGridLayout;
	grid_UnitCategories->addWidget(label_UnitCategory, 0, 0);
	grid_UnitCategories->addWidget(comboboxCategories, 1, 0);
	grid_UnitCategories->addWidget(lst_CategoriesView, 2, 0);
	qgb_GroupUnitCategories->setLayout(grid_UnitCategories);

	return qgb_GroupUnitCategories;
}

QGroupBox* QConvert::createUnitSelectionGpBox()
{
	qgb_UnitSelection = new QGroupBox(tr("Unit Selection"));

	strListModel_units_selection = new QStringListModel();

	createUnitSelectionsList();
	connect(comboboxCategories, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &QConvert::createUnitSelectionsList);

	grid_UnitSelection = new QGridLayout;
	grid_UnitSelection->addWidget(lst_UnitsView_from, 0, 0);
	grid_UnitSelection->addWidget(lst_UnitsView_to, 0, 1);
	qgb_UnitSelection->setLayout(grid_UnitSelection);

	return qgb_UnitSelection;
}

QGroupBox * QConvert::createUnitConversionGpBox()
{
	qgb_UnitConversion = new QGroupBox(tr("Conversion Panel"));
	
	grid_UnitConversion = new QGridLayout;
	lineEdit_input = new QLineEdit(this);
	lineEdit_output = new QLineEdit(this);
	label_input = new QLabel(tr("Input"), this);
	label_output = new QLabel(tr("Output"), this);
	
	grid_UnitConversion->addWidget(label_input, 0, 0);
	grid_UnitConversion->addWidget(lineEdit_input, 1, 0);
	grid_UnitConversion->addWidget(label_output, 0, 1);
	grid_UnitConversion->addWidget(lineEdit_output, 1, 1);
	
	qgb_UnitConversion->setLayout(grid_UnitConversion);
	
	return qgb_UnitConversion;
}

void QConvert::createActions()
{
	qa_Quit = new QAction(tr("&Quit"), this);
	qa_Quit->setIcon(QIcon::fromTheme("application-exit"));
	connect(qa_Quit, &QAction::triggered, this, &QConvert::close);

	qa_About = new QAction(tr("&About"), this);
	connect(qa_About, &QAction::triggered, this, &QConvert::about);

	qa_AboutQt = new QAction(tr("&About Qt"), this);
	connect(qa_AboutQt, &QAction::triggered, this, &QConvert::aboutQt);
}

void QConvert::createUnitCategoriesList()
{
	list_of_UnitCategories << "Show all Categories" << "Electrics" << "Mechanics" << "Physics";
	comboboxCategories->insertItems(0, list_of_UnitCategories);

	list_of_UnitCategories  << tr("Speed") << tr("Weight");
	strListModel_categories->setStringList(list_of_UnitCategories);

	lst_CategoriesView->setModel(strListModel_categories);
	lst_CategoriesView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}


void QConvert::createUnitSelectionsList()
{
	switch(comboboxCategories->currentIndex())
	case 2:
	{
		list_of_units_Mechanics << "μm" << "mm" << "in" << "cm" << "m" << "km";
		strListModel_units_selection->setStringList(list_of_units_Mechanics);

		lst_UnitsView_from->setModel(strListModel_units_selection);
		lst_UnitsView_from->setEditTriggers(QAbstractItemView::NoEditTriggers);

		lst_UnitsView_to->setModel(strListModel_units_selection);
		lst_UnitsView_to->setEditTriggers(QAbstractItemView::NoEditTriggers);

		break;
	}
}

void QConvert::createMenus()
{
	qm_File = menuBar()->addMenu(tr("&File"));
	qm_File->addAction(qa_Quit);

	qm_Info = menuBar()->addMenu(tr("&Info"));
	qm_Info->addAction(qa_About);
	qm_Info->addAction(qa_AboutQt);
}

void QConvert::about()
{
	About* a = new About(this);
	a->show();
}

void QConvert::aboutQt()
{
	QApplication::aboutQt();
}
