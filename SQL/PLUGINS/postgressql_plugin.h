#ifndef POSTGRESSQL_PLUGIN_H
#define POSTGRESSQL_PLUGIN_H

class QString;

#include "adak_sql.h"

class ADAK_SQL;

class POSTGRESSQL_PLUGIN : public ADAK_SQL
{
public:
    POSTGRESSQL_PLUGIN                                      ( QList<ADAK_SQL_STRUCT *> adak_sql_struct ,QString db_name );
    ~POSTGRESSQL_PLUGIN                                     ( );

    int                 LOCK_ROW                            ( const QString id_column_name,const QString table_name, const QString where_info);

    void                UNLOCK_ROW                          ( const QString id_column_name,const QString table_name, const QString where_info);

    void                SET_CLIENT_CODEC                    ( );

    void                SET_TABLE_AUTO_INCREMENT_ID_VALUE   ( const QString p_table_name, const QString p_id_column_name, int p_last_auto_inc_value );

    DB_DRIVER           GET_SQL_DRIVER_ENUM                 ( );
    QString             GET_SQL_DRIVER_NAME                 ( );
    QString             GET_SQL_DRIVER_DEFAULT_DB_NAME      ( );

    QString             OPEN_CREATE_TABLE_SQL               ( const QString &table_name );
    QString             CLOSE_CREATE_TABLE_SQL              ( TABLE_STRUCT current_table );
    QString             CREATE_COLUMN_SQL                   ( const QString& column_name,
                                                              COLUMN_TYPE    column_type,
                                                              int            length,
                                                              bool           is_auto_increment,
                                                              bool           is_not_null,
                                                              bool           is_array,
                                                              INDEX_TYPE     index_type        );

    bool                IS_DB_HAS_MULTIPLE_INSERT           ();
    QString             GET_MULTIPLE_INSERT_DIVIDER         ();
    QString             CREATE_MULTIPLE_INSERT_HEADER       (const QString &table_name,const QString &id_column_name, const QString &insert_column_names);
    QString             CREATE_MULTIPLE_INSERT_BODY         (const QString &table_name,const QString &id_column_name, const QString &insert_column_names,const QString &insert_column_values);
    QString             CREATE_MULTIPLE_INSERT_FOOTER       (const QString &table_name,const QString &id_column_name, const QString &insert_column_names);

    QString             DROP_TABLE_SQL                      ( const QString& table_name );
    QString             GET_TABLE_NAMES_SQL                 ( );
    QString             GET_COLUMN_NAMES_SQL                ( const QString &table_name, const QString& database_name);
    QString             ADD_ONE_COLUMN_SQL                  ( int column_number, TABLE_STRUCT current_table );
    QString             GET_COLUMN_TYPE_NAME                ( COLUMN_TYPE p_column_type, int is_array = 0 );

    void                SQL_PREPARE_QUERY                   ( QString * table_name, QString *id_column_name, QString *column_names, QString *where_condition, int sql_operation);
    QString             CREATE_SELECT_QUERY                 ( QString * table_name, QString * column_names   , QString * where_condition    ,QString * group_by,QString * order_by, int baslanilacak_satir , int secilecek_satir_sayisi);
    QString             CREATE_INSERT_QUERY                 ( QString * table_name, QString * id_column_name , QString * insert_column_names,QString * insert_column_values);

    int                 GET_ID_USING_DRIVER                 ( QSqlQuery * query );

};

#endif // POSTGRESSQL_PLUGIN_H








