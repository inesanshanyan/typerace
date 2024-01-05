<?php
if (!function_exists('dms_fs')) {
    // Create a helper function for easy SDK access.
    function dms_fs()
    {
        global $dms_fs;

        if (!isset($dms_fs)) {
            // Include Freemius SDK.
            require_once dirname(__FILE__) . '/vendor/freemius/start.php';
            $dms_fs = fs_dynamic_init(array('id' => '6959', 'slug' => 'domain-mapping-system', 'premium_slug' => 'domain-mapping-system-pro', 'type' => 'plugin', 'public_key' => 'pk_e348807215df985c848c86b883ee3', 'is_premium' => true, 'premium_suffix' => 'PRO', 'has_addons' => false, 'has_paid_plans' => true, 'menu' => array('slug' => 'domain-mapping-system', 'support' => false, 'parent' => array('slug' => 'domain-mapping-system',),), 'is_live' => true,));
        }

        return $dms_fs;
    }

    dms_fs();
    // Signal that SDK was initiated.
    function dms_fs_custom_icon()
    {
        return dirname(__FILE__) . '/assets/img/dms-logo.jpg';
    }

    dms_fs()->add_filter('plugin_icon', 'dms_fs_custom_icon');
    do_action('dms_fs_loaded');

    if (dms_fs()) {
        global $wpdb;
        require_once plugin_dir_path(__FILE__) . 'includes/dms.class.php';
        require_once plugin_dir_path(__FILE__) . 'includes/dms-activate.class.php';
        require_once plugin_dir_path(__FILE__) . 'helpers/dms-helper.class.php';
        require_once plugin_dir_path(__FILE__) . 'helpers/dms-mdm-import.class.php';
        require_once plugin_dir_path(__FILE__) . 'api/dms-api.class.php';
        DMS::defineProperties(plugin_basename(__FILE__), plugin_dir_path(__FILE__), plugin_dir_url(__FILE__), '1.9.0', dms_fs(), $wpdb);
        DMS::includePlatforms();
        add_action('rest_api_init', array('DMS_API', 'routes'));
        add_action('init', array('DMS', 'checkVersion'), 1, 1);
        add_action('init', array('DMS', 'run'), 1, 1);
        add_action('init', array('DMS', 'prepareUriFilters'), 1, 1);
        add_action('init', array('DMS', 'loadTextDomain'), 10);
        add_action('init', array('DMS', 'detectMdmPresence'), 10);
        add_action('admin_init', array('DMS', 'adminInit'));
        add_action('admin_menu', array('DMS', 'adminMenu'));
        add_action('upgrader_process_complete', array('DMS', 'upgraderProcessComplete'), 10, 2);
        add_action('wp', array('DMS', 'catchQueriedObject'), 10, 1);
        add_action('pre_get_posts', array('DMS', 'preGetPosts'));
        add_action('wp_head', array('DMS', 'postRewriteBack'), 99, 1);
        add_action('template_redirect', array('DMS', 'forceRedirect'));
        add_action('wp_head', array('DMS', 'showCustomHtml'));
        add_filter('redirect_canonical', array('DMS', 'preventHomeRedirect'), 1, 2);
        add_filter('plugins_url', array('DMS', 'pluginsUrl'), 10, 3);
        add_filter('admin_url', array('DMS', 'rewriteAdminUrlStatic'), 10, 4);
        add_action('transition_post_status', array('DMS', 'hookAfterSavePost'), 10, 3);
        add_filter('get_site_icon_url', array('DMS', 'doFavicon'));
        dms_fs()->add_action('after_uninstall', array('DMS', 'uninstall'));
        // TODO check this
        // dms_fs()->add_action( 'install.version.upgraded', array( 'DMS', 'upgraderProcessComplete' ) );
    }

}

register_deactivation_hook(__FILE__, array('DMS', 'deactivate'));
register_activation_hook(__FILE__, array('DMS', 'activate'));