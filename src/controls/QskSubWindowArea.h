/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_SUB_WINDOW_AREA_H
#define QSK_SUB_WINDOW_AREA_H 1

#include "QskGlobal.h"
#include "QskControl.h"

class QskGradient;
class QskSubWindow;

class QSK_EXPORT QskSubWindowArea : public QskControl
{
    Q_OBJECT

    Q_PROPERTY( QskGradient gradient READ gradient
        WRITE setGradient RESET resetGradient NOTIFY gradientChanged FINAL )

    using Inherited = QskControl;

public:
    QSK_SUBCONTROLS( Panel )

    QskSubWindowArea( QQuickItem* parent = nullptr );
    virtual ~QskSubWindowArea();

    void setGradient( const QskGradient& gradient );
    QskGradient gradient() const;
    void resetGradient();


Q_SIGNALS:
    void gradientChanged();

protected:
    virtual void geometryChangeEvent( QskGeometryChangeEvent* ) override;

    virtual bool eventFilter( QObject*, QEvent* ) override;
    virtual bool mouseEventFilter( QskSubWindow*, const QMouseEvent* );

    virtual void itemChange( ItemChange, const ItemChangeData& ) override;

private:
    virtual void setDragging( QskSubWindow*, bool );
    virtual void setActive( QskSubWindow*, bool );

    class PrivateData;
    std::unique_ptr< PrivateData > m_data;
};

#endif
