/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_RANGE_CONTROL_H
#define QSK_RANGE_CONTROL_H

#include "QskControl.h"

class QSK_EXPORT QskRangeControl : public QskControl
{
    Q_OBJECT

    Q_PROPERTY( qreal minimum READ minimum WRITE setMinimum NOTIFY minimumChanged )
    Q_PROPERTY( qreal maximum READ maximum WRITE setMaximum NOTIFY maximumChanged )
    Q_PROPERTY( qreal range READ range NOTIFY rangeChanged )
    Q_PROPERTY( qreal value READ value WRITE setValue NOTIFY valueChanged )

    Q_PROPERTY( qreal stepSize READ stepSize WRITE setStepSize NOTIFY stepSizeChanged )
    Q_PROPERTY( int pageSize READ pageSize WRITE setPageSize NOTIFY pageSizeChanged )

    Q_PROPERTY( bool snap READ snap WRITE setSnap NOTIFY snapChanged )

    using Inherited = QskControl;

  public:
    QskRangeControl( QQuickItem* parent = nullptr );
    ~QskRangeControl() override;

    bool pressed() const;

    qreal minimum() const;
    qreal maximum() const;

    qreal range() const;
    qreal position() const;

    qreal value() const;

    qreal stepSize() const;
    int pageSize() const;

    void setSnap( bool );
    bool snap() const;

    void setReadOnly( bool );
    bool isReadOnly() const;

  public Q_SLOTS:
    void setValue( qreal );
    void setMinimum( qreal );
    void setMaximum( qreal );
    void setStepSize( qreal );
    void setPageSize( int );

    void stepUp();
    void stepDown();
    void pageUp();
    void pageDown();

  Q_SIGNALS:
    void minimumChanged( qreal );
    void maximumChanged( qreal );
    void rangeChanged( qreal );
    void valueChanged( qreal );
    void stepSizeChanged( qreal );
    void pageSizeChanged( qreal );
    void snapChanged( bool );
    void readOnlyChanged( bool );

  protected:
    virtual qreal fixupValue( qreal value ) const;
    void keyPressEvent( QKeyEvent* event ) override;

#ifndef QT_NO_WHEELEVENT
    void wheelEvent( QWheelEvent* ) override;
#endif

    void componentComplete() override;

  private:
    void adjustRangeAndValue( bool );

    class PrivateData;
    std::unique_ptr< PrivateData > m_data;
};

#endif
