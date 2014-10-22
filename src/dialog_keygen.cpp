/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 22-10-2014
///		Date update	: 22-10-2014
///		Comment		:
/// ============================================================================
#include <QApplication>
#include <QFileDialog>

#include <QDebug>
#include <QCryptographicHash>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QMessageBox>

#include "dialog_keygen.h"

namespace espira
{

namespace widgets
{
/// ############################################################################
///			class dialog_keygen
/// ############################################################################
/// :: begin
///
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
    ///	dialog_keygen( )
    /// ------------------------------------------------------------------------
    dialog_keygen::dialog_keygen( QWidget *parent, Qt::WindowFlags f ) :
        QDialog( parent, f )
	{
        this->initialize( );
	}

    /// ------------------------------------------------------------------------
    ///	~dialog_keygen( )
    /// ------------------------------------------------------------------------
    dialog_keygen::~dialog_keygen( )
	{
        qDebug() << "dialog_keygen destroyed";
    }

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
    /// --------------------------------------------------------------------
    /// hash( )
    /// ------------------------------------------------------------------------
    QString dialog_keygen::hash( ) const
    {
        QString s_pwd( this->_txt_pwd->text( ) );
        return QString(
                        QCryptographicHash::hash( s_pwd.toUtf8( ),
                                                  QCryptographicHash::Md5 ).toHex( )
                      );
    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
	///	initialize( )
    /// ------------------------------------------------------------------------
    void dialog_keygen::initialize( )
    {
        this->setWindowTitle( tr( "Authorization" ) );

        this->init_layout( );

        this->init_connections( );

        this->setSizePolicy( QSizePolicy::Minimum, QSizePolicy::Minimum );
    }

    /// ------------------------------------------------------------------------
	///	init_layout( )
    /// ------------------------------------------------------------------------
    void dialog_keygen::init_layout( )
    {
        QVBoxLayout *vl = new QVBoxLayout;
        vl->setMargin( 5 );
        vl->setSpacing( 10 );

        vl->addWidget( this->init_full_name( ) );
        vl->addWidget( this->init_login( ) );
        vl->addWidget( this->init_pwd( ) );
        vl->addWidget( this->init_buttons( ) );

        this->setLayout(vl);
    }

    /// ------------------------------------------------------------------------
    ///	init_connections( )
    /// ------------------------------------------------------------------------
    void dialog_keygen::init_connections( )
    {
        //load
        this->connect(
                        this->_btn_load, SIGNAL( clicked( ) ),
                        this, SLOT( load_keyfile( ) )
                     );
        //accept
        this->connect(
                        this->_btn_ok, SIGNAL( clicked( ) ),
                        this, SLOT( accept( ) )
                     );
        //reject
        this->connect(
                        this->_btn_cancel, SIGNAL( clicked( ) ),
                        this, SLOT( reject( ) )
                    );
    }

    /// ------------------------------------------------------------------------
    ///	init_full_name( )
    /// ------------------------------------------------------------------------
    QWidget *dialog_keygen::init_full_name( )
    {
        QWidget *widget = new QWidget( this );

        QVBoxLayout *vl = new QVBoxLayout;
        vl->setMargin( 0 );
        vl->setSpacing( 0 );

        QLabel *lbl = new QLabel( tr( "user\'s full name:" ) );
        lbl->setAlignment( Qt::AlignLeft|Qt::AlignVCenter );
        vl->addWidget( lbl );

        this->_txt_full_name = new QLineEdit;
        this->_txt_full_name->setMaxLength( 128 );
        vl->addWidget( this->_txt_full_name );

        widget->setLayout(vl);

        return widget;
    }

    /// ------------------------------------------------------------------------
    ///	init_login( )
    /// ------------------------------------------------------------------------
    QWidget *dialog_keygen::init_login( )
    {
        QWidget *widget = new QWidget( this );

        QVBoxLayout *vl = new QVBoxLayout;
        vl->setMargin( 0 );
        vl->setSpacing( 0 );

        QLabel *lbl = new QLabel( tr( "login:" ) );
        lbl->setAlignment( Qt::AlignLeft|Qt::AlignVCenter );
        vl->addWidget( lbl );

        this->_txt_login = new QLineEdit;
        this->_txt_login->setMaxLength( 16 );
        vl->addWidget( this->_txt_login );

        widget->setLayout(vl);

        return widget;
    }

    /// ------------------------------------------------------------------------
    ///	init_pwd( )
    /// ------------------------------------------------------------------------
    QWidget *dialog_keygen::init_pwd( )
    {
        QWidget *widget = new QWidget( this );

        QVBoxLayout *vl = new QVBoxLayout;
        vl->setMargin( 0 );
        vl->setSpacing( 0 );

        QLabel *lbl = new QLabel( tr( "pwd:" ) );
        lbl->setAlignment( Qt::AlignLeft|Qt::AlignVCenter );
        vl->addWidget( lbl );

        this->_txt_pwd = new QLineEdit;
        this->_txt_pwd->setMaxLength( 16 );
        this->_txt_pwd->setEchoMode( QLineEdit::Password );
        vl->addWidget( this->_txt_pwd );
        widget->setLayout(vl);

        return widget;
    }

    /// ------------------------------------------------------------------------
	///	init_buttons( )
    /// ------------------------------------------------------------------------
    QWidget *dialog_keygen::init_buttons( )
    {
        QWidget *widget = new QWidget( this );
        QHBoxLayout *hl = new QHBoxLayout;
        hl->setMargin( 0 );
        hl->setSpacing( 5 );

        hl->addStretch( 1000 );

        this->_btn_load = new QPushButton( tr("Load...") );
        hl->addWidget( this->_btn_load );

        this->_btn_ok = new QPushButton( tr("OK") );
        hl->addWidget( this->_btn_ok );

        this->_btn_cancel = new QPushButton( tr("Cancel") );
        hl->addWidget( this->_btn_cancel );

        widget->setLayout( hl );

        return widget;
    }

    /// ========================================================================
    ///		SLOTS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    ///	load_keyfile( )
    /// ------------------------------------------------------------------------
    void dialog_keygen::load_keyfile( )
    {
        //пытаемся выбрать файл ключа
        QString s_file = QFileDialog::getOpenFileName(
                                           0, tr( "select keyfile" ),
                                           QApplication::applicationDirPath( ),
                                           QString("*.*")
                                                        );

        if( s_file.length( ) )
        {
        }
    }

/// class dialog_keygen :: end
/// ############################################################################

/// ############################################################################
///			class keygen_data
/// ############################################################################
/// :: begin
///
    /// ------------------------------------------------------------------------
    ///	signature( )
    /// ------------------------------------------------------------------------
    QString keygen_data::signature( )
    {
        return QString( );
    }

/// class keygen_data :: end
/// ############################################################################

}//namespace widgets

}//namespace espira
