/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_TEXT_LABEL_H
#define QSK_TEXT_LABEL_H

#include "QskControl.h"

class QskTextOptions;

class QSK_EXPORT QskTextLabel : public QskControl
{
    Q_OBJECT

    Q_PROPERTY( QString text READ text WRITE setText NOTIFY textChanged )

    Q_PROPERTY( int fontRole READ fontRole
        WRITE setFontRole NOTIFY fontRoleChanged )

    Q_PROPERTY( QColor textColor READ textColor
        WRITE setTextColor NOTIFY textColorChanged )

    Q_PROPERTY( QskTextOptions textOptions READ textOptions
        WRITE setTextOptions NOTIFY textOptionsChanged )

    Q_PROPERTY( Qt::Alignment alignment READ alignment
        WRITE setAlignment NOTIFY alignmentChanged )

    using Inherited = QskControl;

public:
    QSK_SUBCONTROLS( Text )

    QskTextLabel( QQuickItem* parent = nullptr );
    QskTextLabel( const QString& text, QQuickItem* parent = nullptr );

    virtual ~QskTextLabel();

    QString text() const;

    void setFontRole( int role );
    int fontRole() const;

    void setTextColor( const QColor& );
    QColor textColor() const;

    void setTextOptions( const QskTextOptions& );
    QskTextOptions textOptions() const;

    void setAlignment( Qt::Alignment );
    Qt::Alignment alignment() const;

    virtual QSizeF contentsSizeHint() const override;

    virtual qreal heightForWidth( qreal width ) const override;
    virtual qreal widthForHeight( qreal height ) const override;

    bool isRichText() const;

    QFont font() const;

Q_SIGNALS:
    void textChanged( const QString& );
    void textColorChanged();
    void textOptionsChanged();
    void fontRoleChanged();
    void alignmentChanged();

public Q_SLOTS:
    void setText( const QString& );

protected:
    virtual void changeEvent( QEvent* ) override;

private:
    class PrivateData;
    std::unique_ptr< PrivateData > m_data;
};

#endif
